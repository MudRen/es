#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("magic robe", "����");
        add( "id", ({ "robe" }) );
        set_short( "����");
        set_long(
                "����һ���ؾ���ʦ�ߴ��ĵķ��ۡ�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set("material","cloth");
        set( "armor_class", 20 );
        set( "defense_bonus", 5 );
        set( "weight", 170 );
        set( "value", ({ 120, "gold" }) );
}
