#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("fire amulet", "�����");
        add( "id", ({ "amulet" }) );
        set_short("�����");
        set_long(
                "����������˵�������������\n"
        );
        set("unit","��");
        set( "type", "misc" );
        set( "material", "leather");
        set( "armor_class", 0 );
        set( "defense_bonus", 8 );
        set( "special_defense",
               ([ "fire":13 ]) );
        set( "no_sale",1);
        set( "weight", 50 );
        set( "value", ({ 100, "gold" }) );
}






