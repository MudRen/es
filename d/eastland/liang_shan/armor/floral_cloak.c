#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("floral cloak", "糺��Ż���");
        add( "id", ({ "cloak","cape" }) );
        set_short("floralcloak","糺��Ż���");
        set_long(
                "This is a red cloak with some floral mark.\n",
                "һ��˫��糺�����磬������\�������Ļ��ƣ�\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 1 );
        set( "weight", 90 );
        set( "value", ({ 1000, "silver" }) );
}