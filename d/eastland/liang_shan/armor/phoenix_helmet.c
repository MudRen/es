#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("phoenix_wing helmet", "����Ͻ��");
        add( "id", ({ "helmet" }) );
        set_short( "phoenix_wing helmet", "����Ͻ��");
        set_long(
                "A metal helmet which is like wing of phoenix.  \n",
                "�������Ͻ��Ƴɵ�ͷ�ڣ���������������� \n"
        );
        set("unit","��");
        set( "type", "head" );
        set( "material", "heavy_metal");
        set( "armor_class", 10 );
        set( "defense_bonus", 4 );
        set( "special_defense",
               ([ "poison":3, "none":3, "mental":2 ]) );
        set( "weight", 70 );
        set( "value", ({ 360, "gold" }) );
}



