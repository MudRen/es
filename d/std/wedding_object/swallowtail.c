#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("swallowtail","��β���");
        add("id",({"suit"}) );
         set_short( "swallowtail","������β��");
        set_long(
"This is a suit of wedding suit made of true white silk meterial.\n",
"����һ����ɫ����β�������׵���ɫ��������Ͼ�İ��顣\n"
        );
        set( "unit", "��" );
        set( "weight", 150 );
        set( "type", "body" );
        set("material","cloth" ) ;
        set( "armor_class", 28 );
        set( "defense_bonus", 5 );
        set( "no_sale", 1 );
        set( "value", ({ 318, "gold" }) );
}
