#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name( "The girl", "������СŮ��" );
	add( "id", ({ "girl" }) );
	set_short( "������СŮ��" );
	set_long(
                "һ���������СŮ���������ҼҾơ�\n"
	);
	set( "race", "dwarf" );
	set( "gender", "female" );
	set( "alignment", 0 );
	set_perm_stat( "str", 6 );
	set( "wealth/gold", 2 );
        set( "hit_points", 80);
        set( "max_hp", 80);
        set("natural_armor_class",8);
        set("natural_defense_bonus",4);

        wield_weapon(OWEAPON"dagger01");
        equip_armor(OARMOR"dudo1");

}
