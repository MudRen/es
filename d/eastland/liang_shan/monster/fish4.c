#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name("common carp", "����");
	add("id",({"fish","carp"}) );
	set_short("����");
	set_long(
		"����һ���ֻ�ɫ�����㣬�������ԣ��Ƕ�����½����Ҫ�ĵ�ˮʳ��\n"
		"�㣬�൱����ζ��\n"
	);
	set( "likefish",1);
	set( "unit", "��" );
	set( "alignment", 200 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 4 );
	set_skill("swimming",100);
	set( "natural_max_damage1", 7 );
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

