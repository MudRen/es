#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith mail", "���黤��");
        add( "id", ({ "mail" }) );
        set_short( "���黤��");
        set_long(
                "����������Ǿ�����ʦ�������Ծ����������ƶ��ɡ�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "element");
        set( "armor_class", 27 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "mental":5 ]) );
        set( "weight", 250 );
        set( "no_sell",1);
        set( "value", ({ 400, "gold" }) );
}






