#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("fur boots", "��Ƥѥ��");
        add( "id", ({ "boots" }) );
        set_short( "��Ƥѥ��" );
        set_long(
                "���Ǿ�������Ƥ�����Ƴɵ�ѥ�� \n"
        );
        set( "unit","˫");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 5 );
        set( "defense_bonus", 0 );
        set( "special_defense",
               ([ "mental":1, "evil":-1 ]) );
        set( "weight", 50 );
        set( "value", ({ 250, "silver" }) );
}
