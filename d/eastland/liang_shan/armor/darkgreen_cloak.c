#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("darkgreen cloak", "�����ް�");
        add( "id", ({ "cloak","cape" }) );
        set_short("darkgreen cloak","�����ް�");
        set_long(
                "This is darkgreen cloak. \n",
                "һ������ɫ�Ķ������������ɫ�����룮\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_defense",(["none":1,"divine":1,"evil":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 490, "silver" }) );
}