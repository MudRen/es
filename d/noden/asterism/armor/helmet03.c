#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("turban", "��ͷ��");
        add( "id", ({ "turban" }) );
        set_short( "��ͷ��");
        set_long(
                "�ؾ����õĲ�ͷ����\n"
        );
        set("unit","��");
        set( "type", "head" );
        set("material","cloth") ;
// set( "armor_class", 3 );
   set( "armor_class", 5 );
// set( "defense_bonus", 7 );
   set( "defense_bonus", 5 );
// fixed by mad
        set( "weight", 30 );
        set( "value", ({ 2, "gold" }) );
}



