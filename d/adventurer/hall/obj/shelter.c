#include "mudlib.h"

inherit CONTAINER;

void create()
{
	object obj1;
	::create();
	set_name("shelf", "���");
	set_short("���");
	set("id", ({"shelf"}) );
	set_c_open_long(@C_LONG
����һ���޴�ĺ�̴ľ��ܣ����������������飬��Щ������
�����������ǰ������������൱�õ�ʱ���ˡ����������⣬���ٴ�
�ĵ�ð���߳����ڽ�����ѯ�����ᣬ����������������ϡ�
C_LONG
	);
	
	set("prevent_get",1);
	set("max_load",2000);
	obj1 = new( "/d/adventurer/hall/obj/letter1" );
	obj1->move( this_object() );
}
void init()
{
      ::init();
      container::init();
      add_action("do_get","get");
}
int do_get(string str)
{
     string s1,s2;
     if (!str) {
         write(
             "Ҫ��ʲ��?\n");
             return 1;
             }
         sscanf(str, "%s from %s", s1, s2);
         if ((!s2) || (lower_case(s2) != "shelf")) return 0;
         
         if ( this_player()->query("class") == "adventurer" )
             return 0;
          
         if ( !present("avery",environment(this_object())) ) return 0; 
          
         write("������������һ�ѣ����: ������ﰡ������������?\n");
         return 1;
}                
