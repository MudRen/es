#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("mithril helmet", "������ͷ��");
        add( "id", ({ "helmet" }) );
        set_short( "a mithril helmet", "������ͷ��");
        set_long(
                "A large helmet made of mithril .\n",
                "������������������Ƴɵ�ͷ��. \n"
                
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "weight", 66 );
        set( "value", ({ 1100, "silver" }) );
}



