#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "����¥����" );
        set_long(
@LONG
����������¥�Ļ������������ܶ���һЩ�������õ��滨��ݣ�
��ض���Ǯ����Ϊ��ȡ����������˶��Ѿ���˼�������ģ�ԭ������
�Ǹ�ϲ��ݪ��Ū�ݵĹ��
LONG
        );
        
        set( "exits", ([ 
		"down"   : Goomay"green_pearl",
        ]) );
        set( "objects", ([
                "lady" : Mob"green_lady",
		]));
        reset();
}

void init()
{
	if (this_player())
                this_player()->set_explore("eastland#10");
}
