#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("holy amulet", "��ʥ�����");
        add( "id", ({ "amulet" }) );
        set_short( "��ʥ�����");
        set_long(
                "���������ܿ������е�а��\n"
        );
        set("unit","��");
        set( "type", "misc" );
        set( "material", "leather");
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "evil":10 ]) );
        set( "weight", 50 );
        set( "value", ({ 300, "gold" }) );
}






