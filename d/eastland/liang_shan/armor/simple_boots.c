#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("general boots", "��Ь");
        add( "id", ({ "boots" }) );
        set_short("general boots", "��Ь");
        set_long(
                "a pair of normal boots .\n",
                "����һ˫�ǳ�ƽ������Ь��������ǰ���������������\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "cloth");
        set( "armor_class", 3 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "none":1, "acid":1 ]) );
        set( "weight", 70 );
        set( "value", ({ 127, "silver" }) );
}
