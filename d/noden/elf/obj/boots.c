#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven boots", "����Ь");
        add( "id", ({ "boots" }) );
        set_short( "����Ь" );
        set_long(
                "���Ǿ������ö�����Ƥ���Ͼ�����������ط������Ƴɵ�Ь�� \n"
                "�������������������ã����Ż����ĽŴ�������ı�����\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "mental":5, "evil":-3, "fire":-1 ]) );
                       
        set( "weight", 50 );
        set( "value", ({ 800, "silver" }) );
}
