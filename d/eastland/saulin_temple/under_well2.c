#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "井中洞穴" );
       set_long( @C_LONG_DESC
你在一个井底的洞穴中，这洞看起来很乾净，同时还有淡淡的香气，又
不是花香，你实在分辨不出是什麽香味，嗯! 这里住的一定是爱乾净又懂生
活情调的生物。
C_LONG_DESC
       );
       set("exits",([
           "out" : SAULIN"under_well1",
       ]) );
       set("objects",([
            "bug1" : SAULIN_MONSTER"small_bug",
            "bug2" : SAULIN_MONSTER"small_bug",
            "bug3" : SAULIN_MONSTER"small_bug",
       ]) );
       reset();
}
void init()
{
        if ( this_player()) this_player()->set_explore("eastland#29");
}
