#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
        set_name("king-kong bracers", "金刚环");
        add( "id", ({"bracers","bracer" }) );
        set_short("金刚环");
        set_long(@C_LONG
一双被上乐金刚 (四臂玛哈嘎拉) 加持过的石手环,
加持以极大之诛法可以帮你诛除一切的内外障。
C_LONG
                );
        set( "unit", "双");
        set( "type", "hands" );
        set("material","stone");
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "weight", 70 );
        set( "value", ({ 1500, "silver" }) );
}
