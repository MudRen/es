//#pragma save_binary

// fixed some word usage, grammer errors. - Elon 03-10-94
#include "moyada.h"

inherit ROOM;

void create()
{
	::create();
   set_short( "Ħ�Ǵ�����" );
	set_long( @LONG_DESCRIPTION
������վ��Ħ�Ǵ�ǵ����ţ�Ħ�Ǵ�ǲ�û�г�ǽ������������
���˱��������������⣬����һ�����ص�ħ�����Χס��ƽ�����˿�
�����ɽ�����磬���ǻ��е���������޷�ͨ����硣����һ����ֱ
��ʯ��·ͨ�������ĵ�Բ�ι㳡�롸��ɫ֮������
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
		"east" : MOYADA"mainrd2.c", 
		"west" : "/d/noden/4,13.noden" ]) );
    set( "pre_exit_func", ([
      "east" : "to_enter",
    ]) );
    set( "no_monster", 1);
    set( "objects", ([
      "guard#1" : MOYADA"monster/moyada_guard",
      "guard#2" : MOYADA"monster/moyada_guard",
    ]) );
	reset();
}

int to_enter()
{
    if( !present("guard") || 
        (this_player()->query("alignment") > (-8000)) )
      return 0;
     tell_object( this_player(),
       "����˵: ��Ǹ! �㲻��ͨ����\n������ֹ�����Ī�Ǵ���\n" );
     tell_room( environment(this_player()),
       "������ֹ"+this_player()->query("c_name")+"����Ī�Ǵ���\n" ,
      this_player()
    );
    return 1;
}
