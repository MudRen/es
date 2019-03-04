#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("fur cloak", "兽皮披风");
        add( "id", ({ "cloak" }) );
        set_short( "兽皮披风" );
        set_long(
                "这是精灵用兽皮所烘制成的披风。\n"
        );
        set( "unit", "件");
        set( "type", "cloak" );
        set( "material", "leather");
        set( "armor_class", 4 );
        set( "defense_bonus", 0 );
        set( "weight", 40 );
        set( "value", ({ 280, "silver" }) );
}
