#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("white lead gloves", "��Ǧ����");
        add( "id", ({ "gloves" }) );
        set_short( "��Ǧ����");
        set_long(
                "����һ˫�ɰ�Ǧ�Ƶ����ס�\n"
        );
        set("unit","˫");
        set( "type", "hands" );
        set("material","light_metal");
        set( "armor_class", 2 );
        set( "defense_bonus", 2 );
        set( "weight", 60 );
        set( "value", ({ 56, "gold" }) );
}






