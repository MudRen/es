#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic leggings", "��ħ�ּ�");
        add( "id", ({ "leggings" }) );
        set_short( "��ħ�ּ�" );
        set_long(
                "���ǹŶ�ħսʿר�õ��ּ�\n"
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "material", "heavy_metal");
        set( "armor_class", 7 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "evil":4, "divine":-3, "cold":-2 ]) );
                       
        set( "weight", 100 );
        set( "value", ({ 200, "gold" }) );
}
