#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic cloak", "��ħ����");
        add( "id", ({ "cloak" }) );
        set_short( "��ħ����" );
        set_long(
                "���ǹŶ�ħսʿ��ר�õ����� \n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "heavy_metal" );
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "special_defense",
              ([ "evil":3, "divine":-4, "fire":2 ]) );
        set( "weight", 80 );
        set( "value", ({ 530, "silver" }) );
}
