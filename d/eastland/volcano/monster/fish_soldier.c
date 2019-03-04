#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "fish soldier", "���" );
	add( "id", ({ "soldier" }) );
	set_short( "���" );
	set_long(
	  "�����һλ��ͷ����Ĺ�����ڿ������������š�\n"
	);
	set( "race", "monster" );
	set( "gender", "male" );
	set( "alignment", 500 );
        set( "likefish",1);
	set_perm_stat( "str", 13 );
	set_perm_stat( "dex", 8 );
	set_perm_stat( "kar", 2 );
	set_skill( "longblade", 40 );
	set_skill( "parry", 40 );
	set_skill( "dodge", 20 );
	set( "hit_points", 200 );
	set( "max_hp", 200 );
	set( "wealth/gold", 15 );
	set( "special_defense", (["all": 10 ]) );
	set_natural_armor( 25, 7 );

	wield_weapon( OWEAPON"blade1" );
}
