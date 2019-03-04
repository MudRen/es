#include <mudlib.h>

inherit WEAPON;

void create()
{    
    set_name( "wood club", "木棒" );
    add( "id", ({ "club" }) );
    set_short( "木棒" );
    set_long(@LONG
一根尺长的木棒，上面缠了一条条的绳子。
LONG
    );
    set( "unit", "根" );
    set( "weight", 80 );
    set( "value", ({ 300, "silver" }) );
    setup_weapon("blunt", 15,5,14);
}
