#include "mudlib.h"
inherit OBJECT;

#define NEED_MEMBERS 1

int create()
{
	seteuid(getuid());
	set_name("invis_obj", "�������");
	set_short("invis_obj" ,"�������");
        set_long(
                 "quest ��Ҫ�Ķ���( �뿴skeleton.c )....\n");
	
	set("unit","��");
        set( "invisible" ,1);
        set("weight",200);
	set("value",({ 0, "silver"}) );
	set("prevent_drop",1);
        set( "extra_look", "$N����һЩ�ˣ�������̧��һ�߾޴������\��\n" );
}

void init()
{
	add_action("to_quit","quit");
	add_action("to_drop","put");
	add_action("to_quit","party");
}

string query_short()
{
  return query("Title")+"[̧��һ�߾޴�����\]" ;
}
int to_quit()
{
      write("���ǻ��ڰᶫ��ร��Ȱ������°�...\n");
      return 1;    
}
int to_drop(string arg)
{	
     int i,num;
     object *usr,me,inv,obj;
     string str;
     
     if( !arg || lower_case(arg) != "skeleton" ) return notify_fail("��ʲ�����?\n");
     me=this_player();
     usr = (mixed *)me->query_temp("party_members");
     num = sizeof(usr);
    
     if ( (string)me->query_temp("leader") != (string)me->query("name") ) {
	       write("ֻ�ж�����쵼�ߣ�����������ม�\n");
	       return 1;
	       }
	       for( i=0; i<sizeof(usr); i++ )
	       {       
	       str = ((usr[i]->query_temp("carry_skeleton",1))?("һ��������....�������ظ��ذ���߾޴�����\����...\n"):"");
	       usr[i]->delete_temp("carry_skeleton");
	       tell_object(usr[i],str );
	       }
	tell_room(environment(me),"�㿴��"+me->query("c_name")+"�����Ķ���\n"
		"��һ����Ȼ���ﶪ������\n", usr);
        obj = new("/d/eastland/liang_shan/obj/skeleton");
        obj->move(environment(me));
	for( i=0; i<sizeof(usr); i++ )
	{
	inv = present("invis_obj",usr[i]);
	if (usr[i] != me) inv->remove();
	}
	inv = present("invis_obj",me);
	inv->remove();
	return 1;
}
