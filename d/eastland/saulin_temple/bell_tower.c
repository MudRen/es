#include "saulin_temple.h"

#include <daemons.h>
#define NEED_FP   200
#define REDUCE_FP  20

inherit ROOM;
inherit STATS_D;

void create()
{
       ::create();
       set_short( "钟楼" );
       set_long( @C_LONG_DESC
你沿著石阶爬上一座高楼，楼上悬著一口巨钟(bell)，黝黑的钟身和绿色的铜锈
，使得这口钟显得厚重异常。在钟旁悬有一根巨木，平时只在凌晨才有专人来撞(hit)
这口钟，就是所谓的 "晨钟" ，但是这口钟也可以用特定的信号召集僧众或传递紧急
消息。据说撞钟的僧人都由寺中一流高手担任，因为巨钟一响，所发出的音波强度，
将会使一个普通人呕血身亡。东侧是一座偏殿。
C_LONG_DESC
               );
       set("light",1);
       set("item_desc",([
         "bell" : @C_LONG
    这是一口大铜钟，它的表面铸出了许\多美丽繁复的花纹，不晓得当初铸它的
高手匠人是怎麽完成的？现在它的表面都已经发黑了，显然它的年岁也不少了，
可是它仍然保养的很好。显然有人常常来看顾它。
C_LONG
]));

       set("exits",([
         "east" : SAULIN"side_temple1",
       ]) );
       reset();
}

void init()
{
     add_action("hit_bell","hit");
}

int hit_bell(string str)
{
     if(!str || str != "bell")
       return notify_fail("你要敲什麽?\n" );
     if( (int)this_player()->query("force_points") < NEED_FP ) {
       this_player()->receive_damage((int)this_player()->query("max_hp")/8);
       tell_object( this_player(), @C_LONG
  你拿起巨木，用力的往钟撞了下去，你感觉到一股音波如排山倒海般的
  从钟口向你涌了过来，把你的五脏六腑震的四分五裂。
C_LONG
);
       tell_object(this_player(),
         "( 你" + status_string() + " )\n");
     } else {
       tell_object( this_player(), @C_LONG
  你拿起巨木，用力的往钟撞x2了下去，你感觉到一股音波如排山倒海般的
  从钟口向你涌了过来，你赶紧运起内力抵抗。
C_LONG
       );
       this_player()->add("force_points", -REDUCE_FP);
     }
        this_player()->set_explore("eastland#28");
     return 1;
}       
