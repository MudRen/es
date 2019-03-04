// rose2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("废墟");
    set_long(@C_LONG
你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。地上有条小径
向南北方向延伸，北方的不远处似乎有流水声传来。这地方阴暗潮湿，却连一
点青苔也没有，你不由得打了个寒噤。
C_LONG
    );
    set("exits", ([
	"north" : AREA"rose3",
	"south" : AREA"rose1"]) );

    reset();
}
