#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("black silk-hood", "��ɴת�Ǵػ���");
        add( "id", ({ "hood","silk-hood" }) );
        set_short( "black silk-hood", "��ɴת�Ǵػ���");
        set_long(
                "A beautiful black silk hood .\n",
                "����һ����ɴͷ���ں��������������ˣ� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":3, "acid":5, "mental":2 ]) );
        set( "weight", 50 );
        set( "value", ({ 306, "gold" }) );
}



