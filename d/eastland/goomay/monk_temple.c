#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "������" );
        set_long("EMPTY\n",
@LONG
���߽�һ�����������Ϲ���һ���Ҷ�����¡�����Ȼ��������λ�ӹ�÷��
�����У�����ȴ������ƾɣ������ϴ��Ľ���Ҳ����Ĳ���ˣ���������Լ��
���д����ü������ࡢ������ȴʹ�����������
LONG
        );
        
        set( "exits", ([ 
		"north" : Goomay"col11",
        ]) );
        
        set( "objects", ([
                "little monk" : Mob"little_monk",
        ]) );
        reset();
#include <replace_room.h>
}

