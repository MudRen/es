#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("battle mirror", "���ľ�");
        add( "id", ({ "mirror" }) );
        set_short("battle mirror", "���ľ�");
        set_long(
                "a mirror for knights .\n",
                "������ǰ����������С���ӣ����ǻ������һ��...\n"
        );
        set( "unit", "��");
        set( "type", "misc" );
        set( "material", "light_metal");
        set( "armor_class", 0);
        set( "defense_bonus", 3 );
        set( "special_defense",
             ([ "poison":5 ]) );
        set( "weight", 20 );
        set( "value", ({ 270, "silver" }) );
}
