#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("golden boots", "�ƽ�Ь");
        add( "id", ({ "boot","boots" }) );
        set_short("�ƽ�Ь");
        set_long(
                "����һ˫�ô�������Ь\n"
        );
        set("unit","˫");
        set( "type", "feet" );
        set( "material", "heavy_metal" );
        set( "armor_class", 8 );
        set( "weight", 100 );
        set( "value", ({ 150, "gold" }) );
}
