#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("lion helmet", "���ʨ�ӿ�");
        add( "id", ({ "helmet" }) );
        set_short( "lion helmet", "���ʨ�ӿ�");
        set_long(
                "A lion face helmet .\n",
                "����һ����ʨ��֮�������Ŀ��ף����ỹ������ɫ����ë \n"
                "����ʮ����׳���䣮\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 9 );
        set( "defense_bonus", 3 );
        set( "weight", 80 );
        set( "value", ({ 288, "gold" }) );
}



