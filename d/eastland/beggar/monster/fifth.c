#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(11);
	set_name( "five-bag beggar", "�������" );
	set("id",({"five","beggar"}));
	set_short( "ؤ�� �������" );
	set_long(@C_LONG
�������������������ߴ����ӵ�ָ����
C_LONG
	);
	set( "unit", "��" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 12 );
	set_skill( "dodge", 50 );
	set( "special_defense", ([ "all": 10 ]) );
	set("race","human");
	set( "gender", "male" );
	set( "alignment", 0 );
	set_natural_armor( 15, 4 );
	set_natural_weapon( 20, 13, 15 );
	set( "natural_weapon_class2", 20 );
	set( "natural_min_damage2", 10 );
	set( "natural_max_damage2", 15 );
	set( "wealth/gold", 30 );
	set_c_verbs( ({ "%s̤����ǰ��һ��ֱȭ����%s", "%s������%sһ��",
		"%sʹһ�С�ɳɮ�ݷ𡹣���ȭ����%s", "%s��ǰһ�ݣ�������%s��ȥ" }) );
}
