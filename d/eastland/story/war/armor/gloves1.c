#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wind gloves","������");
        add("id",({"gloves"}) );
        set_short("������");
	set_long(@C_LONG
һ�������ƶ�Ĵ���ɫ���ף������ò�˿��֯���ɵġ�
C_LONG	         );
	set( "unit", "��" );
	set( "weight",40 );
	set( "type", "hands" );
        set("material","cloth");
	set( "armor_class", 3 );
	set( "defense_bonus", 2 );
	set( "value", ({ 2000, "silver" }) );
}
