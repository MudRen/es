#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("yellow boots", "��Ƥ�ĵ�ѥ");
        add( "id", ({ "boots" }) );
        set_short("yellow boots", "��Ƥ�ĵ�ѥ");
        set_long(
                "This is a pair of boots made of fur of cow .\n",
                "�������Ϻ�СţƤ���Ƶ�ƤЬ��Ь���и������־��\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 50 );
        set( "value", ({ 680, "silver" }) );
}
