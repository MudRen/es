#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�������" );
	set_long(
	"��ɽկ�ھ���һ���ֵ���һ�����������ʯ���̳ɵģ����۲��۵Ľ�\n"
	"������˵��Ϊ�˼����һ���ϴ�: ���������˸�\��\�������ֵ����ԣ��и�\n"
	"ɫ�����ĵ��̣�ÿһ����̵����ⶼ�õĺܣ�ֻ�������̵����⣬��û��\n"
	"���ƣ�������һ����㳡��\n"
	);
	set( "light",1 );
        set_outside( "eastland" );
        set( "no_monster",1);
        set( "exits", ([
                "east" : TROOM"store",
                "south"  : TROOM"path1",    
                "north"  : TROOM"flag",
                "west" : TROOM"wineshop"
        ]) );
}
int clean_up() { return 0; }