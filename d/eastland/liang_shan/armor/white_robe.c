#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("milky cape", "乳白□丝战袍");
        add( "id", ({ "cloak","cape" }) );
        set_short("milky cape","乳白□丝护袍");
        set_long(
                "This is a milky cape for fighters\n",
                "这是一件乳白色的战袍，看起来平平凡凡．\n"
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "special_defense",(["none":3,"divine":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 675, "silver" }) );
        set( "extra_skills",(["dodge":10]));
}