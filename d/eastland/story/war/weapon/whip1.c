#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "Raingod's whip", "雨神鞭" );
    add( "id", ({ "whip" }) );
    set_short( "雨神鞭" );
    set_long(@LONG
一根长逾六十尺的鞭子，鞭子上面有许多突出来的刺。
LONG
    );
    set( "unit", "根" );
    set( "weight", 50 );
    set( "value", ({ 1000, "silver" }) );
    setup_weapon("whip", 30,13,22);
}
