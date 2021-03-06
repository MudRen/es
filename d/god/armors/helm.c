#include <mudlib.h>

inherit ARMOR;

string C_NAME="魔神头盔";

void create()
{
        set_name( "damogorgod helmet", C_NAME );
        add( "id", ({ "helmet" }) );
        set_short( C_NAME );
        set_long(
                "无名之盔。\n"
        );
        set( "unit", "顶" );
        set( "type", "head" );
        set( "material", "knight" );
        set( "armor_class", 20 );
        set( "extra_skills", ([ "riding":20 ]) );
        set( "weight", 80 );
        set( "value", ({ 300, "gold" }) );
}
