#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name( "elven leggings", "�����ּ�");
        add( "id", ({ "leggings" }) );
        set_short( "�����ּ�" );
        set_long(
                "���Ǿ������ö�����Ƥ���Ͼ�����������ط������Ƴɵ��ּ� \n"
                "�������������������ã����Ż������ȴ�������ı�����\n"
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "material", "leather" );
        set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "mental":8, "evil":-5, "fire":-2 ]) );
        set( "weight", 40 );
        set( "value", ({ 100, "gold" }) );
}
