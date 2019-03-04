// File: /d/noden/asterism/tower2-2.c
//                              by Indra in Eastern Story
#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("���˸����ĵڶ���");
	set_long(
		@C_LONG_DESCRIPTION
�����ǰ�˹���ɶ����а��˸����ĵڶ���,һ����ɱ������������˵�.����ķ���
ʮ��ǿ��,������������������֮��,�������ÿһ�㶼�����˺����� ,�Է�ֹ���˵�
����.��ϸһ������ԭ����һ�������Ȼ�վ,���˵��˻���౻������������.
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"up"  : ASTR"tower2-3",
		"down": ASTR"tower2-1",
		]) );
	set("pre_exit_func",([
	    "up":"to_up",
	    ]) );
	set("objects",([
	    "guard"  :MOB"dwarf_guard01",
	    "soldier":MOB"dwarf_soldier01",
	    "healer" :MOB"dwarf_healer",
	    ]) );
	reset();
}

int to_up()
{
   if (present("guard")) 
     {
      if( ((string)this_player()->query("race")) =="dwarf")
         { 
           if( ((int)this_player()->query_level())<10 ) return 0 ;
      
           write(
                    "�������㵲������.\n"
                    "����˵:�������δǬ��С������ȥ���� ? �ؼ������� ?\n");
           tell_room( this_object(),
                    "������"+this_player()->query("c_name")+"��������.\n"
                    "����˵:�������δǬ��С������ȥ���� ? �ؼ������� ?.\n"
                     ,this_player());
           return 1 ;
         }

       write(
       "�������㵲������.\n"
       "����˵:�����ߵ�Ψһ������̤���ҵ�ʬ����ȥ.\n"
       );
       tell_room( environment(this_object()),
          "������"+this_player()->query("c_name")+
          "��������.\n"
          "����˵:�����ߵ�Ψһ������̤���ҵ�ʬ����ȥ.\n"
                              ,this_player());
     return 1;
     }
   return 0;   
}
