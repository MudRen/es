#include "../oldcat.h"

inherit ARMOR;

void create()
{
        set_name("cloud leggings", "�����ּ�");
        add( "id", ({ "leggings" }) );
        set_short("�����ּ�");
        set_long(
                "����ּ����Ǿ���������ǿ����������ո��ƻ��ɵġ�\n"
        );
        set("unit","��");
        set( "type", "legs" );
        set( "material", "element");
        set( "armor_class", 6 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "electric":5 ]) );
        set( "weight", 70 );
        set( "value", ({ 250, "gold" }) );
}






