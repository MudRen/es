#include <mudlib.h>
#include <weather_d.h>
#include <daemons.h>

inherit ROOM;

void create()
{
        ::create();

        set_short("MI room", "һ�̹�");
        if ( (int)this_player()->query("alignment") < -200 ) {
                set_long( 
                 @C_LONG_DESCRIPTION
һ�̹ݡ�������������һ�̹ݵ��ſڣ�����һ���е��ƾɵĴ�ľ�ݡ�
C_LONG_DESCRIPTION
        );
	} else {
                set_long( 
                 @C_LONG_DESCRIPTION
�����ɵģ�͸���ֵ�΢���ĵƹ�ֻ����һ�����ӵ�������������û�еƹ⡣
C_LONG_DESCRIPTION
        );
                }
        set( "light", 1 );
        set( "exits",([
                       "up"  : "/d/healer/building/healer_guild.c",  
                      ]) );
}

int clean_up() {  return 0; }
