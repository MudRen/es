#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven cloak", "��������");
        add( "id", ({ "cloak" }) );
        set_short( "��������" );
        set_long(
                "���Ǿ������ö�����Ƥ���Ͼ�����������ط������Ƴɵ����� \n"
                "�������������������ã����Ż����������������ı�����\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "leather");
        set( "armor_class", 4 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "mental":5, "evil":-3, "fire":-2 ]) );
        set( "weight", 80 );
        set( "value", ({ 1200, "silver" }) );
}
