#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name("silk gloves", "˿������");
        add( "id", ({"gloves" }) );
        set_short("˿������");
        set_long(
                "һ˫˿������,������������ʹ�ø�������\n"
        );
        set( "unit", "˫");
        set( "type", "hands" );
        set( "armor_class", 1 );
        set( "defense_bonus", 4 );
        set( "material","cloth" );
        set( "weight", 30 );
        set( "value", ({ 1250, "silver" }) );
}
