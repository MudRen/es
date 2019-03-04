#include <mudlib.h> 
inherit ARMOR;

void create()
{
        set_name("headband", "必胜头带");
        set_short("a headband", "必胜头带");
        set_long(
                "A cloth headband .\n",
    "这是一条用银兽的皮甲编成的厚头带，一般都是将它绑在头上用来祈求胜利。 \n"
    "它上面布满汗水和灰尘，还有黄色的细沙。 \n"
        );
        set("unit","条");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "fire":1, "cold":1, "electric":-2 ]) );
        set( "weight", 45 );
        set( "value", ({ 100, "gold" }) );
}



