#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("huge mithril helmet", "��������ͷ��");
        add( "id", ({ "helmet" }) );
        set_short( "a mithril helmet", "��������ͷ��");
        set_long(
                "A huge helmet made of mithril .\n",
                "������������������Ƴɵ�ͷ��. \n"
                
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 0 );
        set( "weight", 80 );
        set( "value", ({ 1800, "silver" }) );
}



