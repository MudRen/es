#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "silver claw", "��צ" );
	add( "id", ({ "claw", "cybilas" }) );
   set_short( "������˹��צ" );
	set_long(
		"�⸱��צ���Ǵ�˵�й�������˹�˵�����������Կ�����צ������һ��\n"
		"������˹�챦ʯ���Ա�Χ�����߿����������顣\n"
	);
	set( "unit", "��" );
	set( "type", "unarmed" );
	set( "weapon_class", 36 );
	set( "min_damage", 14 );
	set( "max_damage", 28 );
	set( "second", 1 );
	set( "weight", 70 );
	set( "value", ({ 540, "silver" }) );
	set( "bleeding", 15 );

	set_c_verbs( ({ "��%s��%sһץ", "%s����һ��Ư�������⣬ɨ��%s",
		"��%s�������͡���һ������%s��ȥ" }) );
}
