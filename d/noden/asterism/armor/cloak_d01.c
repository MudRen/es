#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Dwarven elder cape", "��������");
        add( "id", ({ "cape" }) );
        set_short( "��������");
        set_long(
                "���ǰ�����ר�õ����磬���������������λ�� \n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set("material","cloth") ;
        set( "armor_class", 7 );
        set( "defense_bonus", 0 );
        set( "weight", 70 );
        set( "value", ({ 155, "gold" }) );
}



