#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith boots", "����Ь");
        add( "id", ({ "boots" }) );
        set_short("����Ь");
        set_long(
                "��˫Ь���Ǿ�����ʦ���������һ��������ƶ��ɡ�\n"
        );
        set("unit","˫");
        set( "type", "feet" );
        set( "material", "element");
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "special_defense",
               ([ "fire":5 ]) );
        set( "weight", 90 );
        set( "value", ({ 280, "gold" }) );
}






