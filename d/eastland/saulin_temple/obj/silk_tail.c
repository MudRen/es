#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "silk tail", "��˿��β" );
	add( "id", ({ "silk","tail" }) );
	set_short( "��˿��β" );
	set_long(
"����һ���úڲ�˿��ɵĻ��ף�ר���������������˵�β�͡�\n"
	);
	set( "unit", "��" );
        set("material","cloth");
	set( "type", "tail" );
	set( "armor_class", 5 );
	set( "weight", 70 );
	set( "value", ({ 240, "silver" }) );
}
