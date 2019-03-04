// File: /d/noden/asterism/city_library.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("ͼ���");
	set_long(
		@C_LONG_DESCRIPTION
������һ����ΰ�Ĵ�����,�ǰ�˹���ɶ�(asterism)�ǵ�ͼ���,�󲿷ݵ��鼮��
�ڵؾ�ħ��ս���б��յĲ�ȱ��ȫ��.��������һЩ�м�ֵ���鼮������������.������
���ҵ��������е�����.�����㽫�ص���԰,���ϱ���һ���ܸߵ���.
C_LONG_DESCRIPTION
	);

	set_outside( "asterism" );
	set( "light", 1 );
        set("c_item_desc",(["tower":"һ�������ĺܺ�ΰ�ĸ���.\n"]));       
	set( "exits", ([ 
		"north":ASTR"city_garden",
		]) );
	reset();
}                         

void init()
{
   add_action("to_enter","enter");
   }
   
   int to_enter(string str)
   {
       if (!str)
        return notify_fail("��ȥ�Ķ���?\n");
       if (str=="tower")      
          {
            write("�����������.\n");
               this_player()->move_player(ASTR"tower3-1",({
                     "%s����������.\n","%s���������.\n",}),"");
             return 1;
           }
      
       if (str=="library")      
          {
            write("�������ͼ���.\n");
               this_player()->move_player(ASTR"lib01",({
                     "%s������ͼ���.\n","%s���������.\n",}),"");
             return 1;      
           }
        return notify_fail("��ȥ�Ķ���?\n");  
  
    }  
