#include <mudlib.h>

inherit ARMOR;

string C_NAME="Ä§Éñ¿ø¼×";

void create()
{
        set_name( "damogorgod platemail", C_NAME );
        add( "id", ({ "plate", "platemail" }) );
        set_short( C_NAME );
        set_long(
                "ÎÞÃû¿ø¼×¡£\n"
        );
        set( "unit", "Ì×" );
        set( "type", "body" );
        set( "material", "knight");
        set( "armor_class", 50 );
        set( "extra_skills", ([ "tactic":20 ]) );
        set( "weight", 100 );
        set( "value", ({ 350, "gold" }) );
}
