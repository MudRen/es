#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("occult plate", "��������");
        add( "id", ({ "mail","plate","platemail" }) );
        set_short("��������");
        set_long(
                "��������\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "light_metal");
        set( "armor_class", 25 );
        set( "defense_bonus", 0 );
        set( "weight", 200 );
        set( "value", ({ 400, "gold" }) );
}