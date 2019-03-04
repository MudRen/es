#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "six-bag beggar", "��������" );
	set("id",({"six","beggar"}));
	set_short( "ؤ�� ��������" );
	set_long(@C_LONG
����������������������󷨡�
C_LONG
	);
	set( "unit", "��" );
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 13 );
	set_skill( "dodge", 70 );
	set_skill( "blunt", 40 );
	set( "special_defense", ([ "all": 12 ]) );
	set("race","human");
	set( "gender", "male" );
	set( "alignment", 100 );
	set_natural_armor( 20, 5 );
	set_natural_weapon( 22, 2, 4 );
	set( "natural_weapon_class2", 20 );
	set( "natural_min_damage2", 13 );
	set( "natural_max_damage2", 17 );
	set( "wealth/gold", 50 );
        wield_weapon(DWEAPON"blunt");
}
