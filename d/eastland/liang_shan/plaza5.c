#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�����䳡" );
	set_long(
	"������ɽկ�������Ĵ����䳡��ƽʱ����ͷ�ֳ嶼�ڴ˲������£�ѵ\n"
	"���񶷻��󷨣����߷�����ʽ�ı��У�����ɭɭ�ĺ��⣮����������ɽ\n"
	"կ�����ķ��������ڴ��������֣����ߵĽ�����Ϊ�㽫̨���ֳ�����Ӧ\n"
	"�������森\n"
	);
	set_outside("eastland");
	set( "light",1 );
        set( "exits", ([
                "east" : TROOM"plaza3",    
                "north"  : TROOM"plate",
                "west" : TROOM"plaza4",
                "south" : TROOM"flag"
        ]) );
        reset();
}
int clean_up() { return 0; }