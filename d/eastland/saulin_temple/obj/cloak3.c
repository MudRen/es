#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "purple cloak", "���ա���" );
	add( "id", ({ "cloak" }) );
	set_short( "���ա���" );
	set_long(
		"���е�����ν֮����, ���ա��������ֺ��д�������,������ɫ���ա�\n"
	);
	set( "unit", "��" );
	set( "type", "cloak" );
        set("material","cloth");
	set( "armor_class", 6 );
	set( "defense_bonus", 2 );
	set( "weight", 40 );
	set( "value", ({ 530, "silver" }) );
}
