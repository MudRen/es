#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("grass carp", "����");
	add("id",({"fish","carp"}) );
	set_short("����");
	set_long(
		"����һ���ֻ�ɫ�Ĳ��㣬���룬�������ף��㴽��Ϊ�ֲڣ���ˮ\n"
		"�ߵĺ̲�Ϊ��ʳ��\n"
	);
	set( "unit", "��" );
	set( "likefish",1);
	set( "alignment", 200 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 8 );
	set_skill("swimming",100);
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

