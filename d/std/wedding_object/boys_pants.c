#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name( "wedding pants", "����");
        add( "id", ({ "pants" }) );
        set_short( "a pair of pants", "��������ĳ���");
        set_long(
                "A pair of wedding pants made of silk.\n",
                "����һ������ɽ��˿֯�ɵĳ��㡣\n"
        );
        set( "unit", "��");
        set( "type", "legs" );
        set( "material","cloth" ) ;
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "weight", 30 );
        set( "no_sale", 1 );
        set( "value", ({ 60, "gold" }) );
}
