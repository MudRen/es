#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("pond loach", "����");
	add("id",({"fish","loach"}) );
	set_short("����");
	set_long(
		"����һ��ϸ�����㣬����Դ��룬ϸС�ĺְ��ܲ�ȫ�������\n"
		"��Ͳ״�Ҳ������Һ����ʹ����Ҫͽ��ץ��������൱���ѡ�\n"
	);
	set( "likefish",1);
	set( "unit", "��" );
	set( "alignment", 100 );
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 6 );
	set("wimpy",8);
	set_perm_stat("dex",16);
	set_skill("dodge",35);
	set_skill("swimming",100);
	set_c_limbs( ({ "ͷ��", "����", "β��" }) );
	set_c_verbs( ({ "%s���죬��%sҧȥ","%sβ������һ˦��˦��%s" }) );
}

