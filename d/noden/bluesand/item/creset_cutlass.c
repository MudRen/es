#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "creset cutlass", "�����䵶" );
	add( "id", ({ "cutlass" }) );
   set_short( "�����䵶" );
	set_long(
		"һ�ѳ������µ��䵶����������ʮ�������������Ͽ���ʮ�������µĿ̺ۡ�\n"
	);
	set( "unit", "��" );
	set( "type", "longblade" );
	set( "weapon_class", 25 );
	set( "min_damage", 8 );
	set( "max_damage", 20 );
	set( "bleeding", 15 );
	set( "weight", 80 );
	set( "value", ({ 1460, "silver" }) );
}
