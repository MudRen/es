#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "buckler", "Բ��" );
   set_short( "Բ��" );
	set_long(
		"���Բ���Ѿ��൱���ˣ����滹��������������ȱ�ڣ�������������Ȼ\n"
		"�൱���á�\n"
	);
	set( "type", "shield" );
	set( "material", "light_metal" );
	set( "weight", 70 );
	set( "armor_class", 2 );
	set( "defense_bonus", 1 );
	set( "value", ({ 285, "silver" }) );
}
