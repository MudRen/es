#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Orb amulet", "ˮ�������");
        add( "id", ({ "amulet" }) );
        set_short( "ˮ�������");
        set_long(
                "һ��ˮ�������,ˮ���Թžͺ��м�ǿħ��,�����ؾ���ʥ\n"
                "����ϴ���ˮ���������еļ�Ʒ��\n"
               );
        set("unit","��");
        set("material","element");
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 10 );
        set( "weight", 5 );
        set( "value", ({ 100, "gold" }) );
}



