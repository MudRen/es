#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "wisp", "���" );
   set_short( "���" );
	set_long(
		"�㿴��һ�ŷ���Ĺ����Ȼ�ܶ��˲����Ź��Ĵ��ڣ���������ǰ��\n"
		"��������������ʵ��ǻ�ģ�\n"
	);
   set( "race", "undead" );
	set( "unit", "��" );
	set( "alignment", -200 );
	set( "natural_defense_bonus", 10 );
	set( "natural_weapon_class1", 4 );
	set( "natural_max_damage1", 4 );
	set( "unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set_skill( "dodge", 35 );
	set_c_verbs( ({"%s����һ��СС�Ļ�����%s", "%s��Ӱ�ӻ���һ�Σ���%s��ȥ" }) );
	set_c_limbs( ({ "����" }) );
}
