#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Bronze amulet", "��ͭ�����");
        add( "id", ({ "amulet" }) );
        set_short( "��ͭ�����");
        set_long(
                " һ����ͭ�����,�������ᵫ���ƺ����ṩ�ܺõı�����\n"
        );
        set("unit","��");
        set( "type", "misc" );
        set("material","light_metal") ;
        set( "armor_class", 0 );
        set( "defense_bonus", 7 );
        set( "weight", 5 );
        set("no_sale",1) ;
        set( "value", ({ 60, "gold" }) );
}



