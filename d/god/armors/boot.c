#include  <mudlib.h>

inherit ARMOR;

string C_NAME="ħ��սѥ";

void create()
{
        set_name("damogorgod boots", C_NAME);
        add( "id", ({ "boots" }) );
        set_short( C_NAME );
        set_long(
                "����֮Ь��\n"
        );
        set( "unit", "˫" );
        set( "type", "feet" );
        set( "material", "knight");
        set( "extra_skills", ([ "defend":20 ]) ); 
        set( "armor_class", 10 );
        set( "weight", 50 );
        set( "value", ({ 150, "gold" }) );
}
