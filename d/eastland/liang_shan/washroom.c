#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "ϴ�·�" );
	set_long(
	"��������ɽ����ϴ�·���Ŀǰ�Ĵ����ν�����Ϊկ�ڲ�������\n"
	"������������ˣ�կ��һ���ݵĸ�Ů���ڴ���ϴ���е��������\n"
	"��һ��ˮ��(well)��\n"
	  
	);
	set( "light",1 );
        set("c_item_desc",(["well":
"�������������ֱ��������Ϊһ����������ȥ����������һ�������ܣ�\n"
            ]));        
        set( "objects", ([
             "boss" : TMONSTER"pang",
             "lady1" : "/d/eastland/goomay/monster/poor_woman",
             "lady2" : "/d/eastland/goomay/monster/poor_woman"
             ]));
        set( "exits", ([
                "north" : TROOM"path3",
                "south" : TROOM"dryroom"
        ]) );
        reset();
}
int clean_up() { return 0; }
/*
void init()
{
     add_action("do_climb","climb");
}
int do_climb(string arg)
{
if (!arg || arg !="well")
return notify_fail(
"��ʲ��\n");
write (
"��û����...:)\n");
} 
*/    