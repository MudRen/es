#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("daemonic amulet", "��ħ�����");
        add( "id", ({ "amulet" }) );
        set_short( "��ħ�����" );
        set_long(
                "���ǹŶ�ħսʿר�õĻ����\n"
        );
        set( "unit", "��");
        set( "type", "misc" );
        set( "material", "heavy_metal");
        set( "armor_class", 0);
        set( "defense_bonus", 5 );
        set( "special_defense",
             ([ "evil":5, "divine":-7 ]) );
        set( "weight", 30 );
        set( "value", ({ 470, "silver" }) );
}
