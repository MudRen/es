#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("elven gloves", "��������");
        add( "id", ({ "glove","gloves" }) );
        set_short( "��������" );
        set_long(
                "���Ǿ������ö�����Ƥ���Ͼ�����������ط������Ƴɵ����� \n"
                "�������������������ã����Ż������ִ�������ı�����\n"
        );
        set( "unit", "˫");
        set( "type", "hands" );
        set( "material", "leather" );
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "mental":6, "evil":-5, "fire":-2]) );
                       
        set( "weight", 40 );
        set( "value", ({ 800, "silver" }) );
        set( "no_sale", 1);
}
