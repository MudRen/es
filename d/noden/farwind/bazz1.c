//#pragma save_binary

#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("΢��·");
	set_long( @C_LONG_DESCRIPTION
������������΢��·�ϡ��㳡λ����������Զ����΢��·��
һ·������ȥ�����ߵĽ������Ǳ���Ψһ�ľưɡ�
C_LONG_DESCRIPTION
	);

	set_outside( "farwind" );
	set( "light", 1 );
	set( "exits", ([
		"north" : "/d/noden/farwind/wineshop",
		"east" : "/d/noden/farwind/bazz2",
		"west" : "/d/noden/farwind/square",
		"south" : "/d/noden/farwind/hocker.c"
	]) );
    create_door("north","south",
		 ([  "keyword" : ({"wooden","door"}),
		     "name"    : "wooden door",
		     "c_name"  : "ľ��",
		     "c_desc"  : "����һ�ȿɰ���Сľ�ţ����Ϲ���һ���Ƶ�����ơ�\n",		
		     "status"  : "open"
		]) );
   reset();

}
