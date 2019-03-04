#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "The General", "�佫" );
	add( "id", ({ "general" }) );
	set_short( "�佫" );
	set_long(
		"�㿴��һλ������������ͷ����Ĺ�������������ȷ�󽫡�\n"
	);
	set( "unit", "��" );
	set( "race", "monster" );
	set( "gender", "male" );
	set( "alignment",  800 );
        set( "likefish",1);
	set( "max_hp", 500 );
	set( "hit_points", 500 );
        set( "max_sp", 1000 );
        set( "spell_points", 1000);
	set( "special_defense", ([ "all": 40, "none" : 20, ]) );
	set( "aim_difficulty", ([ "critical" : 35, "vascular" : 25, ]) );
	set_natural_armor( 38, 20 );
	set_natural_weapon( 6, 3, 12 );
	set( "wealth/gold", 15 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 23 );
        set_perm_stat( "con", 20 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
        set("chat_chance",10);
        set("chat_output", ({
         "�佫�������û�п�������������\n"
        }) );

	wield_weapon(OWEAPON"staff1" );
	equip_armor( OARMOR"mail8" ); 
	equip_armor( OARMOR"armband3" );
}
