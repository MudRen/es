#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name("golden carp", "����");
	add("id",({"fish","carp"}) );
	set_short("����");
	set_long(
		"����һ������ɫ�����㣬������ֽ������꣬�������Ϊ���ǵ���\n"
		"����ʳ�ԣ����������󶼴���ζ֮�ʡ�\n"
	);
	set( "unit", "��" );
	set( "likefish",1);
	set( "alignment", 300 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 3 );
	set_skill("swimming",100);
	set( "natural_max_damage1", 7 );
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

