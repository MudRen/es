#include <mudlib.h>

void create(object ob)
{
    if ( !ob ) return ;
	ob->set_level(13);
	ob->set_name( "troll", "山丘巨人" );
	ob->set_short( "山丘巨人" );
	ob->set_long(
		"这个又大又笨的巨人正守在这里收过路费。\n"
	);
	ob->set_perm_stat( "str", 28 );
	ob->set_perm_stat( "dex", 10 );
	ob->set_perm_stat( "int", 10 );
	ob->set_skill( "chain", 70 );

	ob->set( "natural_armor_class", 30 );
	ob->set( "natural_defense_bonus", 5 );
	ob->set( "time_to_heal", 2 );
	ob->set( "max_hp", 600 );
	ob->set( "hit_points", 600 );
	ob->set( "gender", "male" );
	ob->set( "alignment", -800 );
	ob->set( "wealth/silver", 400 );

	ob->set( "chat_chance", 15 );
	ob->set( "chat_output", ({
		"山丘巨人说道: 慢著，小子！\n",
		"山丘巨人说道: 把钱留下来，不然有的你受的。\n",
		"山丘巨人说道: 我不是在开玩笑，把你身上的钱全部留下来！\n"
	}) );

	ob->wield_weapon("/d/noden/item/morning_star");

	ob->equip_armor("/d/noden/item/wolf_hide");
}
