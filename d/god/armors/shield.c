#include <mudlib.h>

inherit ARMOR;

string C_NAME="����֮ʯӢ��";

void create()
{
        set_name( "damogorgod shield", C_NAME );
        add( "id", ({ "shield" }) );
        set_short( C_NAME );
        set_long(
                "����֮�ܡ�\n"
        );
        set( "unit", "��" );
        set( "type", "shield" );
        set( "material" ,"knight");
        set( "armor_class", 20 );
        set( "extra_skills", ([ "block":20 ]) );
        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}
