// File: /d/noden/asterism/tower2-1.c 
//                              by Indra in Eastern Story

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("���˸����ĵײ�");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����а��˸����ĵײ�,һ����ɱ������������˵�.����ķ���
ʮ��ǿ��,������������������֮��,�������ÿһ�㶼�����˺����� ,�Է�ֹ����
����.
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"out" : ASTR"city14",
		"up"  : ASTR"tower2-2",
		"down": ASTR"tower2-0",
		]) );
	set("pre_exit_func",([
	    "up":"to_up",
	    ]) );
	set("objects",([
	    "guard#1":MOB"dwarf_guard01",
	    "guard#2":MOB"dwarf_guard01",
	    ]) );
	reset();
}

int to_up()
{
   if (present("guard")) 
      {
      if((string)this_player()->query("race")=="dwarf")
         { 
           if( ((int)this_player()->query_level())<15 ) return 0 ;
      
           write(
                    "�������㵲������.\n"
                    "����˵:�������δǬ��С������ȥ���� ? �ؼ������� ?\n"
                      );
           tell_room( this_object(),
                    "������"+this_player()->query("c_name")+"��������.\n"
                    " ����˵:�������δǬ��С������ȥ���� ? �ؼ������� ?.\n"
                     ,this_player());
           return 1 ;
         }
      write(
      "�������㵲������.\n"
      "����˵:�����ߵ�Ψһ������̤���ҵ�ʬ����ȥ.\n");
      tell_room( environment(this_object()),
                 "������"+this_player()->query("c_name")+"��������.\n"
                 "����˵:�����ߵ�Ψһ������̤���ҵ�ʬ����ȥ.\n"
                              ,this_player());
     return 1;
    }
   return 0 ;   
}
