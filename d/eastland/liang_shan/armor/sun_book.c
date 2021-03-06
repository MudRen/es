#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("suntsu", "孙子兵法");
        add( "id", ({ "book" }) );
        set_short("孙子兵法");
        set_long(
                "这是闻名於世的孙子兵法，得到它就会拥有安邦定国之力...\n"
        );
        set( "unit", "本");
        set( "type", "misc" );
        set( "material", "scholar");
        set( "armor_class", 0);
        set( "defense_bonus", 6 );
        set( "special_defense",
             ([ "mental":6, "none":-6 ]) );
        set( "weight", 30 );
        set( "value", ({ 1470, "silver" }) );
        set( "extra_skills",(["tactic":10]));
}
