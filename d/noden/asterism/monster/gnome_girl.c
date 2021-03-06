#include "../asterism.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(3);
	set_name( "Gnome little girl", "地精小女孩" );
	add ("id", ({ "girl", "gnome","little girl" }) );
   set_short( "地精小女孩" );
	set_long(
                 "一个地精小女孩.看她好像正专注於研读手上的书。\n");

    set ("alignment",200 );
    set( "gender", "female" );
    set( "race", "gnome" );
    set( "unit", "个" );
	set_perm_stat( "dex", 6 );
	set ("wealth", ([ "silver": 5 ]) );
	set_natural_weapon(3,1,5);
	set_natural_armor(20,0);
    set ("weight", 200);
    wield_weapon(WEAPONS"small_dagger");
}
