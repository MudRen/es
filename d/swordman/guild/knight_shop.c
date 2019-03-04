#include <mudlib.h>

inherit SELLER;
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "��ʿ�̵�");
	set_long( @LONG_DESCRIPTION
This is a simple room created by roommaker.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
��������������ʿ�����ڲ���������̵꣬�������Ķ�����Ȼ���Ƕ��ã���
����춸���������������ʿ���ԣ�һЩ����װ���������������ģ�����Է���\
���ϵļ�Ŀ��(menu)������������Щʲ�ᡣ
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : "/d/knight/fortress/knight_inner" ]) );
	set( "item_func", ([ 
		"menu" : "show_menu" ]) );
	set_inventory( ({
		({ "/d/knight/fortress/weapons/battleaxe", 3, 3 }),
		({ "/d/knight/fortress/weapons/waraxe", 5, 5 }),
		({ "/d/knight/fortress/weapons/longsword", 10, 10 }),
		({ "/d/knight/fortress/weapons/shortsword", 15, 15 }),
		({ "/d/knight/fortress/armors/chainmail", 10, 10 }),
		({ "/d/knight/fortress/armors/shield", 10, 10 }),
	}) );
	reset();
}

void reset()
{
	room::reset();
	seller::reset();
}