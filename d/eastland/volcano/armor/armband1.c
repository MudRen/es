#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("prayer armband", "�����ֻ�");
        add( "id", ({ "armband" }) );
        set_short("�����ֻ�");
        set_long(
                "����һ�������õ��ֻ���\n"
        );
        set("unit","ֻ");
        set( "type", "arms" );
        set( "material", "light_metal");
        set( "armor_class", 2 );
        set( "weight", 70 );
        set( "value", ({ 20, "gold" }) );
}






