#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "龙王寝宫" );
	set_long(
@LONG
这里是龙王的寝宫，整个房间散发出柔和的光芒，一张用象牙撑起大床，
被子看不出是用什麽质料缝制而成，但一定相当轻且柔软，墙壁上挂著一
幅画乃是出自天下第一丹青手－－沈双双之手，地上铺著厚厚的地毯，房
间中还摆\了一盆罕见的碧玉香，据说是菊花的一种。
LONG
	);
	set( "exits", ([
	     "south" : OTEMP"palace4",
	]) );
        set("objects",([
            "dragon_king":OMONSTER"dragon_king",
            ]) );
         set("light",1);
         reset(); 
}
