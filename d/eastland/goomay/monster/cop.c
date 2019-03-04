
#include <../goomay.h>

inherit Army;

void create()
{
	::create();
	set_level(9);
	set_name( "Policeman", "����" );
	add( "id", ({ "cop" }) );
	set_short( "����" );
	set_long(
		"����һ����÷��Ĳ��죬���ó��Ĳ��Ǵ��ץ�������ǻ������������̼ҡ�\n"
	);
	set( "gender", "male" );
	set( "race", "hawkman" );
        set( "alignment", -100 );
	set_natural_armor( 30, 10 );
	set_natural_weapon( 10, 5, 5 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "kar", 15 );
	set_skill( "whip", 60 );
	set_skill( "parry", 60 );
	set( "hit_points", 290 );
	set( "max_hp", 290 );
	set( "wealth/gold", 10 );
	set( "special_defense", ([ "all": 20 ]) );
//	set ("moving",1);
//	set ("speed",35);
	wield_weapon( Obj"iron_chain" );
	equip_armor( Obj"black_robe" );
	equip_armor( Obj"black_hat" );
}
