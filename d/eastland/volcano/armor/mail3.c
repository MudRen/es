#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("volcano-rocks chainmail", "火山岩锁子甲");
        add( "id", ({ "chainmail" }) );
        set_short( "火山岩锁子甲");
        set_long(
                "这件锁子甲乃是用火山岩制成。\n"
        );
        set("unit","件");
        set( "type", "body" );
        set( "material", "stone");
        set( "armor_class", 18 );
        set( "weight", 290 );
        set( "value", ({ 120, "gold" }) );
}






