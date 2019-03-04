#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "crazy rat", "������" );
	add( "id", ({ "rat" }) );
	set_short( "������" );
	set_long(@CLONG
��ֻ���������ƺ����ˣ�˫������˸��Ѫ��ɫ����ɣ���ע�⵽���Ĳ���
�Ϻ������ʲ�ᶫ����
CLONG
	);

	set_perm_stat("dex", 10 );
	set_perm_stat("str", 12 );
	set_skill( "dodge", 50 );

	set_c_verbs( ({ "%s��צ����ץ%s", "%s������%sҧ��",
		"%ş�����ȣ�����%s", "%s��ǰ�ʹܣ���צ����%s����" }) );
	set_c_limbs( ({ "ͷ��", "����", "ǰצ", "����", "β��" }) );

	set( "aggressive", 1 );
	set( "unit", "ֻ" );
	set( "natural_armor_class", 25 );
	set( "natural_weapon_class1", 14 );
	set( "natural_min_damage1", 6 );
	set( "natural_max_damage1", 6 );
	set( "max_hp", 160 );
	set( "hit_points", 160 );
}
