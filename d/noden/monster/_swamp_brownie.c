#include <mudlib.h>

void create(object ob)
{
	object ob1;

    if ( !ob ) return ;
	ob->set_level(13);
	ob->set_name( "swamp brownie", "������" );
	ob->add( "id", ({ "brownie", "swamp" }) );
	ob->set_short( "������" );
	ob->set_long(
		"���������ɫƤ���������������ض�����΢Ц��\n"
	);
	ob->set_perm_stat( "dex", 20 );
	ob->set_perm_stat( "int", 20 );
	ob->set_perm_stat( "kar", 20 );
	ob->set_skill( "dagger", 70 );
	ob->set_skill( "dodge", 80 );
	ob->set_skill( "anatomlogy", 70 );
	ob->set_temp( "aiming_loc", "vascular" );
	ob->set( "moving", 1 );
	ob->set( "speed", 50 );
	ob->set( "wimpy", 140 );
	ob->set( "special_defense", (["all": 35 ]) );

	ob->set_natural_armor( 40, 14 );
	ob->set_natural_weapon( 6, 6, 10 );

	ob->set( "gender", "female" );
	ob->set( "alignment", 800 );
	ob->set( "wealth/gold", 150 );

	ob->wield_weapon("/d/noden/item/stiletto");
	ob->equip_armor("/d/noden/item/amber_ring");
	seteuid(getuid());
	ob1 = new( "/d/noden/moyada/obj/true_mirror" );
	ob1->move( ob );
}
