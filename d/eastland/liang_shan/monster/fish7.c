#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name("swamp eel", "����");
	add("id",({"fish","eel"}) );
	set_short("����");
	set_long(
		"����һ���޴�������������ǲ��������״�ߣ���ɫ���\n"
		"���ݼ�ϸ�������������˶������������̲�ǿ������⹦\�á�\n"
	);
	set( "unit", "��" );
	set( "likefish",1);
	set( "pursuing",1);
	set( "alignment", 200 );
	set( "natural_weapon_class1", 9 );
	set( "natural_min_damage1", 6 );
	set( "natural_max_damage1", 13 );
	set_skill("swimming",100);
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

