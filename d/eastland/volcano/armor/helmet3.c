#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("fish_lether hat", "��Ƥñ");
        add( "id", ({ "hat" }) );
        set_short( "��Ƥñ");
        set_long(
                "�ⶥ��Ƥñ��ʹ�˴����᲻�·紵���\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "electric":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 230, "gold" }) );
        set( "no_sell",1);
}






