#include "iigima.h"

//inherit DOORS;
inherit ROOM;

void create()
{

        ::create();
        set_short( "perotice's room","檀香房");
        set_long(
        @C_LONG
这里是一间明亮的厢房，四周传来阵阵的檀香，想必这里的主人一
定是个深居简出的人。角落有一面铜镜，和一些粉彩，好像都是女生的
东西，左边墙上挂著一幅人像素描，旁边还放有一张桌子，上头有一封
拆开来的信，右边墙上则挂著一个刻有花纹的盾牌。
C_LONG
        );

        set( "light",1 );
        set( "exits", ([
                     "out": DROW"r25",
        ]) );
        set("objects", ([
             "perotice": DRO"knight",
        ]) );
	reset();
}

int clean_up() { return 0; }
           
