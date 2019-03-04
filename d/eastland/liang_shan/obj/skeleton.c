#include "mudlib.h"
inherit OBJECT;

#define NEED_MEMBERS 1

int create()
{
	seteuid(getuid());
	set_name("skeleton", "\巨大的髑髅\");
	set_short("\巨大的髑髅\");
        set_long("这具巨大的髑髅\，看起来像是人类的遗骸，但是却异常的巨大，\n"
                 "更怪的是，在头上竟然生了两只利角，你看了不禁倒吸一口凉气。\n"
                 "不过不管怎麽说，一个死人是不会威胁到你的....\n"
                 "它看起来蛮重的，不知道是那个家伙把它放(put) 在这?\n");
	set("unit","具");
        set("weight",3000);
	set("value",({ 0, "silver"}) );
	set("prevent_get",1);
	set("prevent_get_c_msg","这东西太重了，最好是两个人以上才抬的(shift)起来\n"+
				"要把他放下，只要(put)它在地上就可以了\n");
	set("prevent_drop",1);
}

void init()
{
	add_action("to_get","shift");
}

int check_member(object *usr)
{
        int i,members=0;
        for( i=0; i<sizeof(usr); i++ ) 
        if (environment(usr[i]) == environment(this_player())) {
			members ++ ;
		}
        if ( members >= NEED_MEMBERS ) 
		return 1;
	return 0;
}
int check_force(object *usr,int num)
{	
	int i,force;
	for( i=0; i<sizeof(usr); i++ ) 
	{ 
		force=usr[i]->query("max_load");
		force-=usr[i]->query("load");
		if( force< 3000/num )
	return 0;
	}
	return 1;
}

int to_get(string arg)
{	
	int i,num;
	object *usr,me,obj;
	if( !arg || arg != "skeleton" ) return notify_fail("拿什麽?\n");
	me=this_player();
        usr = (mixed *)me->query_temp("party_members");
	num = sizeof(usr);
	if ( !check_member(usr)) 
		return notify_fail("糟糕 !! 这实在太重了又不好施力，找个人帮你吧 !!\n"); 
	else if ( (string)me->query_temp("leader") != (string)me->query("name"))
		return notify_fail("只有队伍的领导者，才能下命令喔。\n"); 
	else if ( !check_force(usr,num)) 
		return notify_fail("你们好像搬不动这具巨大的髑髅\，丢掉一些装备吧\n");
        for( i=0; i<sizeof(usr); i++ ) 
	{	usr[i]->set_temp("carry_skeleton",1); 
		tell_object(usr[i],"一，二，三....你费尽吃奶的力气把它拿起来\n");
                obj = new("/d/eastland/liang_shan/obj/invis_load");
        	obj->set("weight",3000/num);
        	obj->move(usr[i]);
	}
	remove();
	return 1;
}
