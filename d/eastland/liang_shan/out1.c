#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "小路" );
	set_long(
"这是一条地图上找不到的小路，两旁长满了长长的芦苇，随风摇曳。\n"	  
"传说这儿常有翦径强人出没，他们会不会就躲在芦丛内呢?\n"
	);
	set_outside("eastland",1);
        set( "exits", ([
                "north" : TROOM"gate1",
                "south" : TROOM"out2"
        ]) );
        reset();
}
void init()
{
object bandit;
if ( random(100)>1 || present("thief") ) return 0;
write(
"突然一声大喊，一个山贼笨手笨脚的从芦丛中钻出，高举著明晃晃的\n"
"钢刀，对你露出暧昧的微笑。\n");
bandit =new("/d/eastland/monster/mt_bandit");
bandit->move(TROOM"out1");
}
int clean_up() { return 0; }