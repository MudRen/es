#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith shield", "�����");
        add( "id", ({ "shield" }) );
        set_short( "�����");
        set_long(
                "��ֻ�����Ǿ�����ʦ��������ħ���������ƶ��ɡ�\n"
        );
        set("unit","ֻ");
        set( "type", "shield" );
        set( "material", "element");
        set( "armor_class", 4 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "magic":5 ]) );
        set( "no_sale",1);
        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}
