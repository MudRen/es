#include <mudlib.h>

inherit ARMOR;

string C_NAME="ħ���ּ�";

void create()
{
        set_name( "demogorgod leggings", C_NAME );
        add( "id", ({ "leggings" }) );
        set_short( C_NAME );
        set_long(
                "�����ּס�\n"
        );
        set( "unit", "��" );
        set( "type", "legs" );
        set( "material", "knight");
        set( "armor_class", 15);
        set( "extra_skills", ([ "riding":20 ]) );
        set( "weight", 80 );
        set( "value", ({ 300, "gold" }) );
}
