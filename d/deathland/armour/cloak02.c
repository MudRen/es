#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("black cloak", "�ڶ���");
        add( "id", ({ "cloak" }) );
        set_short("black cloak", "�ڶ���");
        set_long(
                "A black robe prayed by Evil Yang,a legendary evil_god .\n",
                "���������봫˵а��Yang��һ������\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_denfese", ([ "evil":4, "divine":-6 ]) );
        set( "weight", 50 );
        set( "value", ({ 1600, "silver" }) );
}
