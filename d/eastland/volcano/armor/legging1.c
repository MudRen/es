#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith leggings", "�����ּ�");
        add( "id", ({ "leggings" }) );
        set_short("�����ּ�");
        set_long(
                "����ּ����Ǿ�����ʦ��������а���������ƶ��ɡ�\n"
        );
        set("unit","��");
        set( "type", "legs" );
        set( "material", "element");
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "evil":5 ]) );
        set( "weight", 80 );
        set( "value", ({ 200, "gold" }) );
}






