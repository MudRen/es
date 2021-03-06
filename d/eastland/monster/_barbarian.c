#include <mudlib.h>

void create(object ob)
{
	if ( ! ob ) return ;
	ob->set_level(7);
	ob->set_name( "barbarian", "野人" );
	ob->set_short( "森林野人" );
	ob->set_long(
		"你看到一个浑身肌肉的野人，他正好奇地瞪著你。\n"
	);
	ob->set( "race", "human" );
	ob->set( "gender", "male" );
	ob->set( "alignment", 400 );
	ob->set_perm_stat( "str", 15 );
	ob->set_perm_stat( "dex", 13 );
	ob->set_perm_stat( "kar", 13 );
	ob->set_skill( "axe", 30 );
	ob->set_skill( "dodge", 50 );
	ob->set( "hit_points", 250 );
	ob->set( "max_hp", 250 );
	ob->set( "wealth/gold", 15 );
	ob->set( "special_defense", (["all": 15 ]) );
	ob->set_natural_weapon( 4, 4, 4 );
	ob->set_natural_armor( 25, 6 );
	ob->wield_weapon( "/d/eastland/obj/stone_axe" );
	ob->equip_armor( "/d/eastland/obj/fur_skirt" );
	ob->equip_armor( "/d/eastland/obj/fur_buskin" );
}
