#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("cloud boots", "����ѥ");
        add( "id", ({ "boots" }) );
        set_short( "����ѥ");
        set_long(
                "��˫ѥ�����������ǳ�����Ь����˵����̤�ƶ��С�\n"
        );
        set("unit","˫");
        set( "type", "feet" );
        set( "material", "element");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "cold":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 280, "gold" }) );
}






