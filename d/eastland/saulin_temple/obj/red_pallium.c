#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "red pallium","�������" );
	add( "id", ({ "pallium","cloth" }) );
	set_short( "�������" );
	set_long(
		"����һ���޺��߼����Ӳ����ʸ����Ĵ�����ġ�\n"
	);
	set( "unit", "��" );
        set("material","cloth");
	set( "type", "body" );
        set( "armor_class", 15 );
        set( "defense_bonus", 5 );
	set( "weight", 150 );
	set( "value", ({ 930, "silver" }) );
}
