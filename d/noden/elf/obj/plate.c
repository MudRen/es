#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("chainmail of elf", "��������");
        add( "id", ({ "mail","chainmail" }) );
        set_short( "��������" );
        set_long(
                "���Ǿ�����������Ľ������ϴ�����Са��ף�����Ƴɵ����ף���\n"
                "����������ĵı��ġ�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "light_metal");
        set( "armor_class", 30 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "mental":5, "evil":-3, "poison":-1 ]) );
        set("no_sale",1);
        set( "weight", 200 );
        set( "value", ({ 400, "gold" }) );
}
