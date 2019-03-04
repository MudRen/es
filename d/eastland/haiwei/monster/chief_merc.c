#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "Chou", "������ͷ" );
	set_short( "������ͷ" );
	set_long("������ͷ�մӾ��Ǳ���һ���ڻ�����������������Ⱦ���Ϣ��\n");
	set( "unit", "��" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 80 );
	set_skill( "thrusting", 80 );
	set_skill( "two-weapon", 80 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "gender", "male" );
	set( "alignment", 300 );
	set_natural_armor( 75, 30 );
	set_natural_weapon( 8, 5, 10 );
	set( "natural_weapon_class2", 8 );
	set( "natural_min_damage2", 5 );
	set( "natural_max_damage2", 10 );
	set( "wealth/gold", 60 );
	set_c_verbs( ({ "%s̤����ǰ��һ��ֱȭ����%s", "%s������%sһ��",
		"%sʹһ�С�ɳɮ�ݷ𡹣���ȭ����%s", "%s��ǰһ�ݣ�������%s��ȥ",
		"%sһ�ǡ����ҷ�Դ����˫ȭֱȡ%s", "%sʹһ�С��ӹ���������˫ȭ��%s��ȥ",
		"%sһ�С��������������������%s", "%sһ�С��ͻ���բ������ȭ��磬ֱȡ%s",
		"%sʹһ�ǡ��ڻ�͵�ġ�����ȭֱ��%s" }) );

	wield_weapon( "/d/eastland/haiwei/obj/pen" );
	wield_weapon2( "/d/eastland/haiwei/obj/pen" );
}
