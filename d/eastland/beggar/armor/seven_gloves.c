#include "../dony.h"

inherit ARMOR;

void create()
{
	set_name( "seven gloves", "�߲�����" );
	add( "id", ({ "seven","gloves" }) );
	set_short( "seven gloves", "�߲�����" );
	set_long(@C_LONG
����һ˫���ǻ۲ݱ�֯���ɵ����ף���˵������������������ǻ�Ŷ !!
C_LONG
	);
	set( "unit", "˫" );
        set("material","cloth");
	set( "type", "hands" );
	set( "weight", 40 );
	set( "armor_class",3 );
        set( "defense_bonus", 5 );
	set( "value", ({ 240, "silver" }) );
}
