#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("wedding cape", "��ɫ��������");
        add( "id", ({ "cape" }) );
        set_short("a wedding cape", "��ɫ��������");
        set_long(
                "A beautiful white wedding cape.\n",
                "һ��������˿���ߵİ�ɫ��������.\n" 
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set("material","cloth");
        set( "weight", 65 );
	set("no_sale",1);
        set( "value", ({ 1800, "silver" }) );
}
