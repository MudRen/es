#include "../asterism.h"
inherit ARMOR;

void create()
{
        set_name("Shinning amulet", "��������Ļ����");
        add( "id", ({ "amulet" }) );
        set_short( "��������Ļ����");
        set_long(
                " һ����������Ļ����\n"
        );
        set("unit","��");
        set( "type", "misc" );
        set("material","cloth") ;
        set( "armor_class", 0 );
        set( "defense_bonus", 7 );
        set( "weight", 15 );
        set( "value", ({ 122, "gold" }) );
}



