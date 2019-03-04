#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "�����䳡" );
	set_long(
	"������ɽկ�������Ĵ����䳡��ƽʱ��\��ͷ�ֳ嶼�ڴ˲������£�ѵ\n"
	"���񶷻��󷨣����߷�����ʽ�ı��У�����ɭɭ�ĺ��⣮����������ɽ\n"
	"կ�����ķ��������ڴ��������֣����������������ģ��������Ŀ��\n"
	);
	set( "light",1 );
        set_outside( "eastland" );
        set( "c_item_desc",(["flag":
        "��Щ���ĸ������ƣ�ֱ����ʣ�����Ṧ���ã����ϲ�ȥ��\n"
        ]));
        set( "exits", ([
                "east" : TROOM"plaza2",
                "south"  : TROOM"path2",    
                "north"  : TROOM"plaza5",
                "west" : TROOM"plaza1"
        ]) );
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
                "zhu":TMONSTER"zhu"
        ]) );        
        reset();
}
void init()
{
add_action("do_climb","climb");
}
int do_climb(string arg)
{
if ( !arg || arg!="flag")
return notify_fail(
"��ʲ��?\n");
write (
"��û���, �����������\n");
}
int clean_up() { return 0; }