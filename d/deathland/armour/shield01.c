#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name( "warlord shield", "ս�����");
        add( "id", ({ "shield" }) );
        set_short("a warlord shield", "ս�����");
        set_long(
                "mithril shield of protection .\n",
           "�������������������������ƳɵĶܣ��������İ��˽���һֱ������ \n"
        );
        set( "unit", "��"); 
        set( "type", "shield" );
        set( "material", "heavy_metal" );
        set( "armor_class", 6 );
        set( "defense_bonus",3 );
        set( "weight", 100 );
        set( "value", ({ 350, "gold" }) );
}






