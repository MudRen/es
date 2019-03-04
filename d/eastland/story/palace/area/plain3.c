#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草地上的小路");
	set_long( @LONG
你正站在一条玉制小路上，小路向西边方向延伸，四周是绿草如茵，东边一座
琼楼高院，庄严豪丽，气象万千，瑶壁上嵌一白玉牌，内镶二字漆金古篆文，其笔
力雄劲，书著「天都」二字。草地上各色繁花，花大如钱，偶一阵微风吹过，花随
同披佛，漫天花香，清馨醒脑，沁人心脾。旁边一玉制石阶。
LONG
	);
	set("light",1);
        set( "exits", ([
              "up" : SPALACE"palace1",
            "west" : SPALACE"plain2"
        ]) );
	reset();
}
