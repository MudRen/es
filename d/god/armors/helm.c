#include <mudlib.h>

inherit ARMOR;

string C_NAME="ħ��ͷ��";

void create()
{
        set_name( "damogorgod helmet", C_NAME );
        add( "id", ({ "helmet" }) );
        set_short( C_NAME );
        set_long(
                "����֮����\n"
        );
        set( "unit", "��" );
        set( "type", "head" );
        set( "material", "knight" );
        set( "armor_class", 20 );
        set( "extra_skills", ([ "riding":20 ]) );
        set( "weight", 80 );
        set( "value", ({ 300, "gold" }) );
}
