#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "ham", "����" );
   set_short( "����" );
	set_long(
		"�㿴��һ����������˼���Ļ���Ư���ڿ���....��\n"
	);
   set( "race", "undead" );
	set( "unit", "��" );
	set( "alignment", -100 );
	set( "natural_defense_bonus", 5 );
	set( "natural_weapon_class1", 2 );
	set( "natural_max_damage1", 2 );
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set_skill( "dodge", 5 );
	set_c_verbs( ({ "%sŤ������ת�˼�Ȧ����%s��ȥ" }) );
	set_c_limbs( ({ "����" }) );
}
