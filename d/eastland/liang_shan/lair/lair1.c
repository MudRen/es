#include <../takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "��խͨ��" );
	set_long(@C_LONG
�������ɽ���е���խͨ������ʪ����������������������һ��˵������
�Ķ�����ζ������ϸ�ķ���������ùζ�������š������ζ���������С��帯
�ܵ�ζ����ǰ������ƺ���ʲ�ᶫ�������������ޱ��޼ʵĿ־建����������
������ĵ�����������Ͽ��뿪...
C_LONG	
	);
        set( "exits", ([
                "out" : TROOM"forest1",
                "north" : TROOM"lair/lair2"
        ]) );
        reset();
}
int clean_up() { return 0; }
