
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("???","广场");
  set_long(@Long
Long
,@CLong
一个很大的广场,地上长满了一些绿色的植物.你抬头一望,只见一个很大很大
的洞通向地上. 似乎那个洞是人工挖掘的,但你不能确定 .在广场的中央有一口井
(well),一些仆人正在井旁打水.另外有一些奇怪的生物飞翔在你的上空,而一些矮
人战士骑在上面控制著.经由过去的听闻你得知那些奇异的生物应该就是传说中才
会出现的狮鹰(griffon).
CLong
);
set("exits",([
               "west":Deathland"/palace/pa_06",
             ]) );
set("c_item_desc",([
    "griffon":@Cgriffon
长著一对翅膀,有著像狮子的头的奇异生物
Cgriffon
    ,"well" : "@@to_look_well",
    ]) );
set("objects",([
    "warrior":Monster"/warrior",    
    ]) );
    
::reset();
}

string to_look_well()
{
     write("当你看著这口井,忽然你的脚滑了一下,你跌进了井里.\n"
          );
     say(this_player()->query("c_name")+"在井旁消失了.\n");
     this_player()->move_player(Deathland"/palace/well01","SNEAK","");
     return "这井的深度并不深,你应该能很容易的爬出去\n";
}

