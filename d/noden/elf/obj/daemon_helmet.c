#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic helmet", "��ħ��");
        add( "id", ({ "helmet" }) );
        set_short( "��ħ��" );
        set_long(
                "���Ƕ�ħսʿ��ר��ͷ�� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "evil":3, "divine":-3, "mental":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 350, "gold" }) );
}


