#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "widow serpent", "�Ѹ���" );
	add( "id", ({ "serpent" }) );
	set_short( "�Ѹ���" );
	set_long(@CLONG
����һ��Ů�˵��������ߵ����壬ʮ���ױ����̵�һ�ֹ�����Ľ���
��Ů�˿����������������ǲ�����ʾ�������ģ����Ǳ�ʾ�����Ӷ��ˣ�
CLONG
	);
	set( "unit", "��" );
	set( "gender", "female" );
	set( "alignment", -1000 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 16 );
	set( "natural_max_damage1", 33 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_skill( "dodge", 80 );

	set( "killer", 1 );
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s�ſ�Ѫ���ڣ���%sҧȥ", "%s��\��β�ͣ�˦��%s" }) );
}
