#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("deer boots", "�Ƥխ��ѥ");
        add( "id", ({ "boots" }) );
        set_short("deer boots", "�Ƥխ��ѥ");
        set_long(
                "This is a pair of boots made of skin of deer .\n",
                "������¹Ƥ���ɵ�խѥ��û��ţƤ������ȴ���Ӽ��ͣ�\n"
        );
        set( "unit", "˫");
        set( "type", "feet" );
        set( "material", "leather");
        set( "armor_class", 7 );
        set( "defense_bonus", 1 );
        set( "weight", 60 );
        set( "value", ({ 640, "silver" }) );
}
