#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black robe", "�����" );
	add( "id", ({ "robe" }) );
	set_short( "an black robe", "�����" );
	set_long(
		"You see a pliceman's black robe.\n",
		"����һ����÷�򲶿�ר�õ��Ʒ���\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
        set("material","cloth");
	set( "weight", 80 );
	set( "armor_class", 15 );
	set( "value", ({ 150, "silver" }) );
}
