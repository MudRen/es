#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("occult plate", "ÉñÃØîø¼×");
        add( "id", ({ "mail","plate","platemail" }) );
        set_short("ÉñÃØîø¼×");
        set_long(
                "ÉñÃØîø¼×\n"
        );
        set("unit","¼ş");
        set( "type", "body" );
        set( "material", "light_metal");
        set( "armor_class", 33 );
        set( "defense_bonus", 2 );
        set( "weight", 200 );
        set( "value", ({ 400, "gold" }) );
}