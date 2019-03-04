// File: /d/noden/asterism/tower3-1.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�ؾ������ĵײ�");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����еؾ������ĵײ㡣���˺Ͱ�����Ϊ��Ƭ���ر�����
���˽���������һ����ۺ�ΰ��ס����������ܵ�ǽ�,����ʽ��ɫ�ı�ʯ���
������ͷס�
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"out" : ASTR"city_library",
		"up"  : ASTR"tower3-2",
		"down": ASTR"tower3-0",
		]) );
	set("pre_exit_func",([
	    "up":"to_up",
	    ]) );
	set("objects",([
	    "guard#1":MOB"gnome_guard",
	    "guard#2":MOB"gnome_guard",
	    ]) );
	reset();
}

int to_up()
{
  if (present("guard")&&(string)this_player()->query("race")=="daemon") 
    {
      write(
           "�������㵲������.\n"
            "����˵:ι!ħ��ġ��㵱�����ǹ�԰,����ľ�ȥ����?\n"
           "\n");
      tell_room( this_object(),
                 "������"+this_player()->query("c_name")+"��������.\n"
                 "����˵:ι!ħ��ġ��㵱�����ǹ�԰,����ľ�ȥ����?\n"
                  , this_player());
     return 1;
     }
   return 0;   
}
