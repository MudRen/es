#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith helmet", "����ͷ��");
        add( "id", ({ "helmet" }) );
        set_short("����ͷ��");
        set_long(
                "���ͷ�����Ǿ�����ʦ�������Դ��֮��Դ���ƶ��ɡ�\n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "element");
        set( "armor_class", 6 );
        set( "defense_bonus", 1 );
        set( "special_defense",
               ([ "energy":5 ]) );
        set( "weight", 120 );
        set( "value", ({ 130, "gold" }) );
}






