#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "mountain1", "山巅" );
    set_long(@C_LONG
你身处一大片浮云里,白茫茫地使你看不到任何东西。 远远望去,隐隐约约有
几座突出云层的小山群,小山群好似戴著一顶顶白色的帽子。在你旁边有好像有一
面光滑的峭壁 ( bluff ) 。
C_LONG
    );
    set( "light",1);
    set( "exit_suppress", ({
           "west"}) );
    set( "exits", ([
       "west":LAKE"mountain2"
    ]) );
    set("c_item_desc",([
        "bluff":"一面光滑的峭壁,似乎要很好的技术才能爬过去。\n"
    ]) );
    reset();
}
init()
{
   add_action("do_climb","climb");
}
int do_climb(string arg)
{
    object player;
    int probability;
    if ( !arg || arg != "bluff" )
       return notify_fail("你要爬什麽?\n");
    player=this_player();
    probability=(int)player->query_skill("climbing")/(int)player->query_level();
    if ( probability+random(5)>7 ) {
       tell_object(player,"你停也不停地一口气爬过了峭壁。\n\n\n\n");
       tell_room(environment(player),sprintf(
          "%s停也不停地一口气爬过了峭壁。\n",player->query("c_name")),player);
       player->move_player(LAKE"mountain4","SNEAK");
       player->receive_damage(10);
       tell_object(player,
          "该死!你由於落下的速度太快而被旁边的树藤给割伤!\n");
       "/d/magic/magic"->report( this_object(), player );
       return 1;  
    } 
    tell_object(player,
        "你使劲吃奶的力气想爬过峭壁,却因为攀爬的技术不好滑了下来。你滚啊滚"+
        ",滚到山脚下去了!\n");
    tell_room(environment(player),sprintf(
       "%s使劲吃奶的力气想爬过峭壁,却因为攀爬的技术不好滑了下来,滚啊滚,滚到山脚下去了!你不禁捧腹大笑。\n",player->query("c_name")),player);
    player->move(LAKE"mountain0","SNEAK");
    player->receive_damage(10);
    "/d/magic/magic"->report( this_object(), player );
    tell_room(environment(player),"有某一个东西滚到你的脚边～～\n",player);
    return 1;    
}
