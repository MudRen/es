#include <../takeda.h>

inherit ROOM;

void create()
{
	object snake;
	::create();
	set_short( "ħ������" );
	set_long(@C_LONG
���������������ħ����ħ��������ı����ĺ�������Χ������....
��������?�㻳����,���ܺ�����ؿ���һЩ��������Ʈɢ�������Χ.
\��\��\��һ��а�������,���ܸо�������а��ĳɷݲ�������.
C_LONG	
	);
        set( "exits", ([
                "out" : TROOM"lair/lair5"
        ]) );
        snake = new(TMONSTER"snake");
        snake->move(this_object());
        reset();
}
int clean_up() { return 0; }
