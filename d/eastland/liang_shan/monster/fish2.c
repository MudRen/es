#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name("top-minnow", "�����");
	add("id",({"fish"}) );
	set_short("�����");
	set_long(
		"ͷ������඼�д�Բ�ۣ��۴��Сͷ�⣬�������ϸ�ݾ۳ɳݴ���\n"
		"��ʳ�ԣ�������Ӧ�Ըߡ�\n"
	);
	set("likefish",1);
	set( "unit", "��" );
	set( "alignment", -100 );
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage1", 1 );
	set( "natural_max_damage1", 3 );
	set_skill("swimming",100);
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

