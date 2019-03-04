#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "wing adult", "羽民壮丁" );
	add( "id", ({ "adult" }) );
	set_short( "羽民壮丁" );
	set_long(@C_LONG
一位典型的羽民族成年男子，他正在忙著处理刚采收下来的葡萄。
C_LONG
        );
        set( "race","羽民" );
	set( "gender", "male" );
	set( "alignment", 100 );
        set_natural_armor(55,2);
        set_natural_weapon( 19,10,20 );
}
