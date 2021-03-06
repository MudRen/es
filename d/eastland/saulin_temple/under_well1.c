#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "枯\井中" );
       set_long( @C_LONG_DESC
你在一个枯\井中，四周都是满是青苔的井壁，由於长期的乾涸，整个
井底都是一条条的裂缝，想必井水是从其中的某些裂缝流出去的。
C_LONG_DESC
       );
       set("exits",([
           "out" : SAULIN"herb_field",
       ]) );
       reset();
}

void init()
{
        add_action( "explore_crack", "explore" );
        add_action( "pass_crack", "pass" );
}

int explore_crack()
{
    if( !(this_player()->query_quest_level("Tenshin's herb")) ) return 0;
    tell_object(this_player(),@ALONG
你小心的察探四周的井壁，发现其中有一个裂缝(crack)好像有生物
进出的痕迹....或许\你可以穿过去(pass)看看。
ALONG
    );
    return 1;
}

int pass_crack(string arg)
{
    
    if( !(this_player()->query_quest_level("Tenshin's herb")) ) return 0;
    if( !arg || arg!="crack" )    
      return notify_fail( "通过什麽？\n" );
    tell_object(this_player(),
      "你用力一挤，竟然穿过裂缝到达另一个地方。\n" 
    );
    this_player()->move_player( SAULIN"under_well2", "SNEAK" );
    return 1;
}
