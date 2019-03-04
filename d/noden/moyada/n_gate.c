//#pragma save_binary

// minor fixes, word usage, grammers.. -Elon 03-10-94
#include "moyada.h"

inherit ROOM;

void create()
{
	::create();
	set_short("North Gate of Moyada", "Ħ�Ǵﱱ��");
	set_long( @LONG_DESCRIPTION
������վ��Ħ�Ǵ�ǵı��ţ�Ħ�Ǵ�ǲ�û�г�ǽ������������
���˱��������������⣬����һ�����ص�ħ�����Χס��ƽ�����˿�
�����ɽ�����磬���ǻ��е���������޷�ͨ����硣����һ����ֱ
��ʯ��·ͨ�������ĵ�Բ�ι㳡�롸��ɫ֮������
LONG_DESCRIPTION
	);

	set_outside( "moyada" );
	set( "exits", ([ 
		"south" : MOYADA"mainrd1.c", 
		"north" : "/d/noden/5,12.noden" ]) );
    set( "pre_exit_func", ([
      "south" : "to_enter",
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
        (this_player()->query("alignment") > -2000) ||
        ((string)this_player()->query("class") == "mage") )
      return 0;
    tell_object( this_player(),
      "����˵: ��Ǹ! �㲻��ͨ����\n������ֹ�����Ī�Ǵ���\n"
    );
    tell_room( environment(this_player()),
      "������ֹ"+this_player()->query("c_name")+"����Ī�Ǵ���\n",
      this_player()
    );
    return 1;
}
