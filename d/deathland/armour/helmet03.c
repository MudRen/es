#include "../echobomber.h"
inherit ARMOR;

void create()
{
        set_name("holy helmet", "��ʥͷ��");
        add( "id", ({ "helmet" }) );
        set_short( "a holy helmet", "��ʥͷ��");
        set_long(
                "A huge helmet enchanted holy power.\n",
                "����һ��������ʥ����ͷ��. \n"
                
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "light_metal" );
        set( "armor_class", 7 );
        set( "defense_bonus", 4 );
        set( "special_defense", ([ "divine":10 ,"none":-5 ]) );
        set( "weight", 100 );
        set( "value", ({ 2000, "silver" }) );
}



