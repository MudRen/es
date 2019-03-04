#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("snake-fish", "������");
	add("id",({"fish","snake"}) );
	set_short("������");
	set_long(
		"����һ���������ص��㣬ѧ��������������һ���˶������ô���\n"
		"��������������������һ���ľͷƯ��ˮ���ʵ�ϣ�����һ������\n"
		"����ʳ�����ࡣ\n"
	);
	set( "likefish",1);
	set( "killer",1);
	set( "pursuing",1);
	set( "unit", "��" );
	set( "alignment", -200 );
	set_skill("swimming",100);
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 14 );
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

