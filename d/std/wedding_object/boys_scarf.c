#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding scarf", "˿�����");
        add( "id", ({ "scarf" }) );
        set_short("a scarf for Gentlemen", "˿�����");
        set_long(
                "A beautiful scarf for gentlemen on meeting.\n",
                "һ����ʿ����ʽ���Ͻ�����\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material","cloth" ) ;
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 55 );
        set( "no_sale", 1 );
        set( "value", ({ 1800, "silver" }) );
}
