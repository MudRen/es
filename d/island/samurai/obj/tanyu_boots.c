#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "tanyu boots", "����սѥ");
        add( "id", ({ "boots" }) );
        set_short("tanyu boots", "����սѥ");
        set_long(@AAA
�������������е�սѥ
AAA
        );
        set( "unit", "˫"); 
        set( "type", "feet" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set("material","light_metal");
        set( "weight", 50 );
        set( "value", ({ 660, "silver" }) );
}
