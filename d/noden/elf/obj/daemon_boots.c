#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic boots", "��ħЬ");
        add( "id", ({ "boots" }) );
        set_short( "��ħЬ" );
        set_long(
                "���ǹŶ�ħսʿר�õ�սѥ\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "heavy_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "evil":4, "divine":-8, "acid":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 440, "silver" }) );
}
