#include "../dony.h"
inherit ARMOR;

void create()
{
        set_name("doctor amulet", "医者护符");
        add( "id", ({ "amulet" }) );
        set_short( "医者护符");
        set_long(@C_LONG
这是一个很普通的护符,上面绣有一堆简要的行医用术语, 与其说是一本字典还比
较恰当。
C_LONG               
               );
        set("unit","个");
        set("material","element");
        set( "type", "misc" );
        set( "armor_class", 0 );
        set( "defense_bonus", 6 );
        set( "weight", 5 );
        set( "value", ({ 110, "gold" }) );
}



