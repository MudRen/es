#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("sweetfish", "����");
	add("id",({"fish"}) );
	set_short("����");
	set_long(
		"����һ���������㣬��ƬϸС�����ѹ������ǰ�˽�ƽ��Ե�о�\n"
		"�ݣ���״�Ʋ��Ա�춹�ʳ��ʯ�ϵ�����Ϊʳ��\n"
	);
	set("likefish",1);
	set( "unit", "��" );
	set( "alignment", 300 );
	set( "natural_weapon_class1", 6 );
	set( "natural_min_damage1", 3 );
	set_skill("swimming",100);
	set( "natural_max_damage1", 6 );
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

