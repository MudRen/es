#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("volcano-rocks plate", "��ɽ������");
        add( "id", ({ "plate" }) );
        set_short( "��ɽ������");
        set_long(
                "������������û�ɽ���Ƴɡ�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "stone");
        set( "armor_class", 28 );
        set( "special_defense", ([ "fire":10 , "cold":-5 ]) );
        set( "weight", 330 );
        set( "value", ({ 160, "gold" }) );
}






