#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("eagle boots", "ӥצƤ�ķ�Ǭ��ѥ");
        add( "id", ({ "boots" }) );
        set_short("eagle boots", "ӥצƤ�ķ�Ǭ��ѥ");
        set_long(
                "This is a pair of boots made of skin of eagle's claw .\n",
                "���ǰ�����ӥ��צ�ϵ�ƤɹǬ�Ƴɵ�Ь�ӣ��������е��ζ��\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 4 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               (["energy":2 ]) );
        set( "weight", 60 );
        set( "value", ({ 640, "silver" }) );
}
