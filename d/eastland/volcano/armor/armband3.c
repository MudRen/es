#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("water armband", "ˮ�ۻ�");
        add( "id", ({ "armband" }) );
        set_short( "ˮ�ۻ�");
        set_long(
                "����ۻ�����������ħ����ˮ֮�����ƶ��ɡ�\n"
        );
        set("unit","��");
        set( "type", "arms" );
        set( "material", "element");
        set( "armor_class", 2 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "cold":-5, "fire":10 ]) );
        set( "weight", 100 );
        set( "value", ({ 100, "gold" }) );
}






