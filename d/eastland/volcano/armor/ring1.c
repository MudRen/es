#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("wraith ring", "�����ָ");
        add( "id", ({ "ring" }) );
        set_short( "�����ָ");
        set_long(
                "��ֻ��ָ���Ǿ�����ʦ�������Ծ綾�������ƶ��ɡ�\n"
        );
        set("unit","ֻ");
        set( "type", "finger" );
        set( "material", "element");
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "special_defense",
               ([ "poison":5 ]) );
        set( "weight", 50 );
        set( "value", ({ 120, "gold" }) );
}






