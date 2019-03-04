#include <mudlib.h>
#include <weather_d.h>
#include <daemons.h>

inherit ROOM;

void create()
{
        ::create();

        set_short("MI room", "一刻馆");
        if ( (int)this_player()->query("alignment") < -200 ) {
                set_long( 
                 @C_LONG_DESCRIPTION
一刻馆。你现在来到了一刻馆的门口，这是一栋有点破旧的大木屋。
C_LONG_DESCRIPTION
        );
	} else {
                set_long( 
                 @C_LONG_DESCRIPTION
黑蒙蒙的！透过街灯微弱的灯光只看见一栋房子的摸样，房间里没有灯光。
C_LONG_DESCRIPTION
        );
                }
        set( "light", 1 );
        set( "exits",([
                       "up"  : "/d/healer/building/healer_guild.c",  
                      ]) );
}

int clean_up() {  return 0; }
