#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("chainmail", "����");
        add( "id", ({ "mail","chainmail" }) );
        set_short( "����" );
        set_long(
                "������Ľ������Ƴɵ����ס�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "light_metal" );
        set( "armor_class", 13 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "mental":3, "evil":-2 ]) );
                       
        set( "weight", 150 );
        set( "value", ({ 300, "silver" }) );
}






