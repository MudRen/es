#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name( "elven shield", "�����");
        add( "id", ({ "shield" }) );
        set_short( "�����" );
        set_long(
                "���Ǿ�����������Ľ������ƳɵĶܣ�������������� \n"
                "�ı��ġ�\n"
        );
        set( "unit", "��"); 
        set( "type", "shield" );
        set( "material", "light_metal");
        set( "armor_class", 8 );
        set( "defense_bonus", 3 );
        set( "special_defense",
               ([ "mental":4, "evil":-3 ]) );
        set( "extra_skill",([ "block":5 ]) );              
        set( "weight", 50 );
        set( "value", ({ 105, "gold" }) );
        set( "no_sale", 1);
}
