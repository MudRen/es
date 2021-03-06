//#pragma save_binary

// sacr.c
// To scarifice the item on the ground to GODS of ES ..
// for cleaning environment of this world , GODS will pay
// some reward for it.

#include <mudlib.h>

inherit DAEMON;

int help();

int cmd_sacrifice(string str)
{
	object *inv,ob;
	mixed *coins;
	int i,cost;
	if ( ! str ) return help();
	inv = ({ });
	if ( str == "all" ) 
	   inv = all_inventory(environment(this_player()));
	else if ( ob = present(str,environment(this_player()))) 
		inv += ({ ob });
	if ( !sizeof(inv)) 
		return notify_fail(sprintf("这里没有 %s 这种东西。\n",str));
	   for ( i =0 ; i < sizeof(inv) ; i++ )	{
		if ( !inv[i] ) continue ;
		if ( living(inv[i]) || inv[i]->query("herb_path")) { 
			if ( str != "all" ) tell_object(this_player(),sprintf("神不接受像%s这种活生生的祭品。\n",inv[i]->query("short")));
				continue ;
		}
		if ( inv[i]->query("prevent_get") || inv[i]->query("name")=="board") {
			tell_object(this_player(),sprintf("神摇摇头，不认为%s是没有用的废物。\n",inv[i]->query("short")));
			continue;
		}
		if ( coins = inv[i]->query("value") ) {
			cost = (int)coins[0]*( (coins[1] == "gold") ? 10 : 1)/20;
			tell_object(this_player(),sprintf("你把%s(%s)奉献给神，",inv[i]->query("short"),inv[i]->query("name")));
			tell_room(environment(this_player()),
				  sprintf("%s把%s(%s)奉献给神。\n",
					  this_player()->query("c_name"),
					  inv[i]->query("short"),inv[i]->query("name"))
				,this_player());
			inv[i]->remove();
			switch ( random(3) ) {
				case 0 : 
					cost++;
					tell_object(this_player(),sprintf("神很高兴的给你 %d 枚银币做奖励。\n",cost ));
					this_player()->add("wealth/silver",cost);
					break;
				case 1 : 
					cost = cost / 2 +1 ;
					tell_object(this_player(),sprintf("神接受你的奉献，赐你 %d 点经验。\n",cost));
					this_player()->gain_experience(cost);
					break;
				case 2 : 
					cost = cost / 10 +1;
					tell_object(this_player(),sprintf("神很欣赏你的环保概念，恢复你 %d 点体力。\n",cost));
					this_player()->receive_healing(cost);
					break;
			}
		} else {
		tell_object(this_player(),
			sprintf("你把%s(%s)奉献给神，但是什麽事也没发生。\n",
				inv[i]->query("short"),inv[i]->query("name")));
		inv[i]->remove();
		}
	   }

	return 1;
}

int help()
{
	write (@HELP
Usage:	sacrifice <item on the ground> 
	sacrifice all

    使用这个命令可以把丢弃在地上的东西奉献给神，以维护环境清洁。
由於赞许你的环保概念，大神会给你小小的奖励。

HELP
);
	return 1;
}
