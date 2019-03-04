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
		return notify_fail(sprintf("����û�� %s ���ֶ�����\n",str));
	   for ( i =0 ; i < sizeof(inv) ; i++ )	{
		if ( !inv[i] ) continue ;
		if ( living(inv[i]) || inv[i]->query("herb_path")) { 
			if ( str != "all" ) tell_object(this_player(),sprintf("�񲻽�����%s���ֻ������ļ�Ʒ��\n",inv[i]->query("short")));
				continue ;
		}
		if ( inv[i]->query("prevent_get") || inv[i]->query("name")=="board") {
			tell_object(this_player(),sprintf("��ҡҡͷ������Ϊ%s��û���õķ��\n",inv[i]->query("short")));
			continue;
		}
		if ( coins = inv[i]->query("value") ) {
			cost = (int)coins[0]*( (coins[1] == "gold") ? 10 : 1)/20;
			tell_object(this_player(),sprintf("���%s(%s)���׸���",inv[i]->query("short"),inv[i]->query("name")));
			tell_room(environment(this_player()),
				  sprintf("%s��%s(%s)���׸���\n",
					  this_player()->query("c_name"),
					  inv[i]->query("short"),inv[i]->query("name"))
				,this_player());
			inv[i]->remove();
			switch ( random(3) ) {
				case 0 : 
					cost++;
					tell_object(this_player(),sprintf("��ܸ��˵ĸ��� %d ö������������\n",cost ));
					this_player()->add("wealth/silver",cost);
					break;
				case 1 : 
					cost = cost / 2 +1 ;
					tell_object(this_player(),sprintf("�������ķ��ף����� %d �㾭�顣\n",cost));
					this_player()->gain_experience(cost);
					break;
				case 2 : 
					cost = cost / 10 +1;
					tell_object(this_player(),sprintf("���������Ļ�������ָ��� %d ��������\n",cost));
					this_player()->receive_healing(cost);
					break;
			}
		} else {
		tell_object(this_player(),
			sprintf("���%s(%s)���׸��񣬵���ʲ����Ҳû������\n",
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

    ʹ�����������԰Ѷ����ڵ��ϵĶ������׸�����ά��������ࡣ
���������Ļ��������������СС�Ľ�����

HELP
);
	return 1;
}
