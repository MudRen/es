#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("black robe", "黑袍");
        add( "id", ({ "cloak","robe" }) );
        set_short("a black robe", "黑袍");
        set_long(
                "A black robe worn by the bishop praying Evil Yang,a legendary evil_god .\n",
                "由祭祀传说邪神Yang的主教所穿的一件黑袍\n"
        );
        set("no_sale",1);
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth");
        set( "armor_class",5  );
        set( "defense_bonus", 5 );
        set( "special_defense", ([ "evil":8, "divine":-12 ]) );
        set( "weight", 50 );
        set( "value", ({ 1400, "silver" }) );
}
