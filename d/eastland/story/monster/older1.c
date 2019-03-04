#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "wing older", "羽民老者" );
	add( "id", ({ "older" }) );
	set_short( "羽民老者" );
	set_long(@C_LONG
一位年岁很大的羽民族人，他在和一旁的老者谈天。
C_LONG
        );
        set( "race","羽民" );
	set( "gender", "male" );
	set( "alignment", 100 );
        set_natural_armor(65,2);
        set_natural_weapon( 25,11,25 );
}
