#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(9);
	set_name( "mercenary", "��ʦ" );
	set_short( "��ʦ" );
	set_long(
		"�����ʦ�մӾ��Ǳ���һ���ڻ�����������������Ⱦ���Ϣ��\n"
	);
	set( "unit", "��" );
	set_perm_stat( "str", 13 );
	set_perm_stat( "dex", 12 );
	set_skill( "dodge", 50 );
	set( "special_defense", ([ "all": 10 ]) );
	set( "gender", "male" );
	set( "alignment", 100 );
	set_natural_armor( 40, 10 );
	set_natural_weapon( 20, 7, 15 );
	set( "natural_weapon_class2", 15 );
	set( "natural_min_damage2", 5 );
	set( "natural_max_damage2", 13 );
	set( "wealth/gold", 20 );
	set_c_verbs( ({ "%s̤����ǰ��һ��ֱȭ����%s", "%s������%sһ��",
		"%sʹһ�С�ɳɮ�ݷ𡹣���ȭ����%s", "%s��ǰһ�ݣ�������%s��ȥ" }) );
#include <replace_mob.h>
}
