#include <mudlib.h>

inherit ARMOR;

string C_NAME="魔神手套";

void create()
{
        set_name( "damogorgod gauntlets", C_NAME );
        add( "id", ({ "gauntlets" }) );
        set_short( C_NAME );
        set_long(
                "无名手套\n"
        );
        set( "unit", "双" );
        set( "type", "hands" );
        set( "material", "knight" );
        set( "armor_class", 10 );
        set( "extra_skills", ([ "parry" :20 ]) );
        set( "weight", 80 );
        set( "value", ({ 250, "gold" }) );
}
