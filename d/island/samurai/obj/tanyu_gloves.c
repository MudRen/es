#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu gloves", "��������");
        add( "id", ({ "gloves" }) );
        set_short("tanyu gloves", "��������");
        set_long(@AAA
�������������е�����
AAA
        );
        set( "unit", "��"); 
        set( "type", "hands" );
        set( "armor_class", 3 );
        set( "defense_bonus", 3 );
        set("material","light_metal");
        set( "weight", 20 );
        set( "value", ({ 560, "silver" }) );
}
