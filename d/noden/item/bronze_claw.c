#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "bronze claws", "��ͭצ" );
	add( "id", ({ "claw", "claws" }) );
   set_short( "��ͭצ" );
	set_long(
		"����һ˫մ������ɫѪ������ͭצ���������൱�ء�\n"
	);
	set( "unit", "˫" );
	set( "second", 1 );
	setup_weapon( "unarmed", 22, 13, 17 );
	set( "bleeding", 15 );
	set( "weight", 140 );
	set( "value", ({ 470, "silver" }) );
	set_c_verbs( ({ "��%s��%sһץ", "%s����һ�������Ѫ�⣬ɨ��%s",
		"��%s��ˢ����һ������%s��ȥ" }) );
}
