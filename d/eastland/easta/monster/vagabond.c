#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "vagabond", "�о�����" );
	set_short( "�о�����" );
	set_long(@C_LONG
�㿴��һ�����ϴ����������̵��о���������������ȭͷ������ǰ
������ȥ��
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -500 );
	set( "aggressive", 1 );
	set( "hit_points", 100 );
	set( "max_hp", 100 );
	set( "time_to_heal", 6 );
	set_natural_armor( 20, 5 );
	set_natural_weapon( 5, 3, 6 );
	set_perm_stat( "str", 6 );
	set_perm_stat( "dex", 4 );
	set_perm_stat( "kar", 1 );
	set( "wealth/gold", 3 );
	set( "special_defense", ([ "all": 20 ]) );
#include <replace_mob.h>
}
