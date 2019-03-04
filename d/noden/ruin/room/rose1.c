// rose1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("废墟");
    set_long(@C_LONG
你来到了一个破旧的废墟，到处散落著颓圮的石柱和石块。地上有条小径
向南北方向延伸。你注意到在不远处的瓦砾堆旁有个小营帐 (camp) ，里面透
出来些微的光亮，似乎是有人居住的样子。到底是谁会住在这个鬼地方呢？
C_LONG
    );
    set("exits", ([
	"north" : AREA"rose2",
	"south" : AREA"rose0",
	"camp" : AREA"camp"
	]) );

    reset();
}
	
