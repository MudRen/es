#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("black robe", "����");
        add( "id", ({ "cloak","robe" }) );
        set_short("a black robe", "����");
        set_long(
                "A black robe worn by the bishop praying Evil Yang,a legendary evil_god .\n",
                "�ɼ��봫˵а��Yang������������һ������\n"
        );
        set("no_sale",1);
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth");
        set( "armor_class",5  );
        set( "defense_bonus", 5 );
        set( "special_defense", ([ "evil":8, "divine":-12 ]) );
        set( "weight", 50 );
        set( "value", ({ 1400, "silver" }) );
}
