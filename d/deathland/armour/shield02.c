#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name( "mithril shield", "���������");
        add( "id", ({ "shield" }) );
        set_short("an mithril shield", "���������");
        set_long(
                "mithril shield of protection .\n",
           "������������������ƳɵĶܣ������������˾��ı���--���ѽ���ľޡ� \n"
        );
        set( "unit", "��"); 
        set( "type", "shield" );
        set( "material", "light_metal" );
        set( "armor_class", 4 );
        set( "defense_bonus", 2 );
        set( "weight", 100 );
        set( "value", ({ 152, "gold" }) );
}






