#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith amulet", "���黤���");
        add( "id", ({ "amulet" }) );
        set_short("���黤���");
        set_long(
                "�����������Ǿ�����ʦ��������ǿ���������ƶ��ɡ�\n"
        );
        set("unit","��");
        set( "type", "misc" );
        set( "material", "element");
        set( "armor_class", 0 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "acid":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 90, "gold" }) );
}






