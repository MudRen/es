#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "龙宫门" );
	set_long(
@LONG_DESCRIPTION
你无法相信你现在所看到的，一座闪曜著碧绿色的光辉的宫殿，宫殿大门是用
珊瑚雕成，以一颗颗珍珠镶在绿玉砌成的阶梯上，屋顶的瓦片其实是红玉，宫
门两旁的柱子刻有龙的浮雕，龙的眼睛镶有紫色的钻石，宫门上面一块白玉扁
额书写著：井龙宫。
LONG_DESCRIPTION
	);
	set( "exits", ([
             "south" : OTEMP"well4",
	     "north" : OTEMP"palace2",
	]) );
        set("objects", ([
            "fish_soldier#1":OMONSTER"fish_soldier",
            "fish_soldier#2":OMONSTER"fish_soldier"
            ]) );
        set("light",1);
        reset();
}
