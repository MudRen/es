#include "mudlib.h"
inherit OBJECT;

#define NEED_MEMBERS 1

int create()
{
	seteuid(getuid());
	set_name("skeleton", "\�޴������\");
	set_short("\�޴������\");
        set_long("��߾޴������\������������������ź�������ȴ�쳣�ľ޴�\n"
                 "���ֵ��ǣ���ͷ�Ͼ�Ȼ������ֻ���ǣ��㿴�˲�������һ��������\n"
                 "������������˵��һ�������ǲ�����в�����....\n"
                 "�����������صģ���֪�����Ǹ��һ������(put) ����?\n");
	set("unit","��");
        set("weight",3000);
	set("value",({ 0, "silver"}) );
	set("prevent_get",1);
	set("prevent_get_c_msg","�ⶫ��̫���ˣ���������������ϲ�̧��(shift)����\n"+
				"Ҫ�������£�ֻҪ(put)���ڵ��ϾͿ�����\n");
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
	if( !arg || arg != "skeleton" ) return notify_fail("��ʲ��?\n");
	me=this_player();
        usr = (mixed *)me->query_temp("party_members");
	num = sizeof(usr);
	if ( !check_member(usr)) 
		return notify_fail("��� !! ��ʵ��̫�����ֲ���ʩ�����Ҹ��˰���� !!\n"); 
	else if ( (string)me->query_temp("leader") != (string)me->query("name"))
		return notify_fail("ֻ�ж�����쵼�ߣ�����������ม�\n"); 
	else if ( !check_force(usr,num)) 
		return notify_fail("���Ǻ���᲻����߾޴������\������һЩװ����\n");
        for( i=0; i<sizeof(usr); i++ ) 
	{	usr[i]->set_temp("carry_skeleton",1); 
		tell_object(usr[i],"һ��������....��Ѿ����̵���������������\n");
                obj = new("/d/eastland/liang_shan/obj/invis_load");
        	obj->set("weight",3000/num);
        	obj->move(usr[i]);
	}
	remove();
	return 1;
}
