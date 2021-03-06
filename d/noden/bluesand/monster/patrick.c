#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "patrick", "派区克" );
	add( "id", ({ "captain" }) );
   set_short( "派区克船长" );
	set_long(
		"派区克船长刚刚为了还赌债，把他的船卖掉了，一个人在这里喝闷酒。\n"
		"如果你识相的话，不要在他面前提起「船(ship)」这个字。\n"
	);
	set( "race", "lizardman" );
	set( "gender", "male" );
	set_perm_stat( "str", 13 );
	set_perm_stat( "dex", 13 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 60 );
	set_skill( "tactic", 80 );

	set( "tactic", "assault" );
	set( "wealth/gold", 25 );
	set( "inquiry", ([
		"ship" : "@@ask_ship"
	]) );

	wield_weapon( "/d/noden/bluesand/item/long_cutlass" );
	equip_armor( "/d/noden/bluesand/item/eye_patch" );
	equip_armor( "/d/noden/bluesand/item/boots" );
}


void ask_ship(object player)
{
	if( query_attacker() ) {
            tell_room( environment(),
                 "派区克船长怒吼道: 连你也敢取笑我？等我解决了这小子再找你算帐！\n",
			this_object() );
	} else {
            tell_room( environment(),
                    "派区克船长脸上一阵青一阵白，大喝: 臭小子！你不要命了？\n",
			this_object() );
		kill_ob( player );
	}
}
