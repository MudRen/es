#include "../asterism.h"

inherit ARMOR;

void create()
{
        set_name("white leather gloves", "��ɫƤ������");
        add( "id", ({ "gloves" }) );
        set_short( "��ɫƤ������");
        set_long(
                "����һ˫��Ƥ���Ƶİ����ס�\n"
        );
        set("unit","˫");
        set( "type", "hands" );
        set("material","leather") ;
        set( "armor_class", 5 );
        set( "defense_bonus", 2 );
        set( "weight", 60 );
        set( "value", ({ 70, "gold" }) );
}






