#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name(" Steel helmet", "�߼��ֿ�");
        add( "id", ({ "helmet" }) );
        set_short( "�߼��ֿ�");
        set_long(
                "����һ������ϸ�ĸ���ͷ�� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set("material","heavy_metal");
        set( "armor_class", 6 );
        set( "defense_bonus", 2 );
        set( "weight", 75 );
        set( "value", ({ 165, "gold" }) );
}



