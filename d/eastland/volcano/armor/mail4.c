#include "../oldcat.h"
inherit ARMOR;

void create()
{
        set_name("volcano-rocks platemail", "��ɽ������");
        add( "id", ({ "platemail" }) );
        set_short( "��ɽ������");
        set_long(
                "������������û�ɽ���Ƴɡ�\n"
        );
        set("unit","��");
        set( "type", "body" );
        set( "material", "stone");
        set( "armor_class", 23 );
        set( "defense_bonus",1);
        set( "special_defense", ([ "fire":5 , "cold":-2 ]) );
        set( "weight", 310 );
        set( "value", ({ 140, "gold" }) );
}






