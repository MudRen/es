#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding boots", "��ͷƤЬ");
        add( "id", ({ "boots" }) );
        set_short("a pair of wedding boots", "��ͷƤЬ");
        set_long(
                "A pair of boots made for wedding.\n",
                "һ˫�ڵķ����ļ�ͷƤЬ��\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material" , "leather" ) ; 
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "no_sale", 1 );
        set( "weight", 100 );
        set( "value", ({ 2450, "silver" }) );
}
