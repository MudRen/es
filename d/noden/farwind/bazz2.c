//#pragma save_binary

#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("΢��·");
	set_long( @LONG_DESCRIPTION
������������΢��·�ϡ��㳡λ����������Զ����΢��·��
һ·������ȥ�����ߵĽ������Ǳ���Ψһ����꣬�ϱ�����һ�����
�Ľ������ƺ����ϵ�ɢ����ǿ�ҵ�ħ����
LONG_DESCRIPTION
	);

	set_outside( "farwind" );
	set( "light", 1 );
	set( "exits", ([
        "north" : "/d/noden/farwind/bookshop",
		"east" : "/d/noden/farwind/bazz3",
		"west" : "/d/noden/farwind/bazz1",
	        "south" : "/d/noden/farwind/auc_room",
	]) );
    create_door("north","south",
    	 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "ľ��",
		     "c_desc"  : "����һ�ȿɰ���Сľ�ţ����Ϲ���һ����������",		
		     "status"  : "open",
		]) );
    reset();
}
