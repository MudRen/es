#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith cloak", "��������");
        add( "id", ({ "cloak" }) );
        set_short( "��������");
        set_long(
                "����������Ǿ�����ʦ����������ʥ�������ƶ��ɡ�\n"
        );
        set("unit","��");
        set( "type", "cloak" );
        set( "material", "element");
        set( "armor_class", 4 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "divine":5 ]) );
        set( "weight", 90 );
        set( "value", ({ 250, "gold" }) );
}






