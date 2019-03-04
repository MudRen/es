#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("Chinese catfish", "����");
	add("id",({"fish","catfish"}) );
	set_short("����");
	set_long(
		"���������ӳ���ͷ���޴󣬳�Բ׶״����Сˮ������Ϊ��ʳ��\n"
		"����������ʳ��ʮ��ζ����\n"
	);
	set( "unit", "��" );
	set( "likefish",1);
	set( "alignment", 200 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 9 );
	set_skill("swimming",100);
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

