#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("blue cloak", "�����");
        add( "id", ({ "cloak","cape" }) );
        set_short("blue cloak","�����");
        set_long(
                "This is blue cloak. \n",
                "һ�����������Ļ��ۣ������·����ֶ��ǣ�\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 4 );
        set( "defense_bonus", 3 );
        set( "weight", 70 );
        set( "value", ({ 490, "silver" }) );
}