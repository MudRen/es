#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set_outside( "eastland" );
        set_short( "����" );
        set_long(
@LONG
����һƬŨ�ܵ����ԣ�΢��������Ũ�ܵ�֦Ҷ��͸����������
�ż����������ƺ����ŵ�һ�������ŵĻ������Ʈ������������ӹ�
������һ��֦Ҷҡҷ���������������\����ľ������ĵ�������һ��
�󶴣���������һ���ʾ��(sign)��
LONG
        );
        
//	set( "exits", ([ 
//		"east" : Goomay"col33",
//	]) );
        set("c_item_desc",(["sign":@C_LONG
    ������ !! ���ϵ��� !! ����ֻ������ĵ�������µ���������
ʲ�ᶫ������û�У�����ֻҪ�㵽�����������ٶ�������һ��ô�
�� .... ��������û����궴��ȥ� !
C_LONG
                            ]));
                                       
        reset();
}
void init()
{
	add_action("to_enter_hole", "enter");
        if (this_player()) this_player()->set_explore("eastland#12");
}

int to_enter_hole( string arg )
{
    if( !arg || arg != "hole" )
      return notify_fail("Ҫ��ȥ���� ?\n");

      this_player()->move_player(Goomay"tunnel2","SNEAK");
    return 1;
}

