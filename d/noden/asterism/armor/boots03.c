#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("platinum boots", "�׽�ѥ");
        add( "id", ({ "boots" }) );
        set_short( "�׽�ѥ");
        set_long(
                "����һ˫�׽������������Ͻ����ɵ�ѥ��.\n"
        );
        set("unit","˫");
        set( "type", "feet" );
        set("material","heavy_metal") ;
        set( "armor_class", 10 );
        set( "defense_bonus", 4 );
        set( "weight", 120 );
        set( "value", ({ 250, "gold" }) );
}






