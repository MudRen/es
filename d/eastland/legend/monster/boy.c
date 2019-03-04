#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "boy", "小男孩" );
	set_short( "小男孩" );
	set_long(@C_LONG
这是渔村里土生土长的小男孩，他正在和其他的小孩在玩，看他玩得不亦乐乎似乎
忽略你的存在。
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
        set_perm_stat( "str", 5 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(30,2);
        set_natural_weapon( 9,5,8 );
}
