#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic platemail", "��ħ�ۼ�");
        add( "id", ({ "mail","platemail" }) );
        set_short( "��ħ�ۼ�" );
        set_long(
                "���Ƕ�ħսʿ��ר�õ��ۼס�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "heavy_metal");
        set( "armor_class", 28 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "evil":8, "divine":-5, "energy":-2 ]) );
        set( "weight", 280 );
        set( "value", ({ 200, "gold" }) );
}
