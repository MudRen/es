#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("偏殿");
    set_long(@LONG
这儿是偏殿，也是阿重霞公主的寝宫。来到此处，只闻满室清香，四处
整理的一尘不染；不过，令你惊讶的是，在此处看不到任何的女工，反倒是
刀、剑，或刀谱、剑谱之类的东西分别放在你的左右，你对阿重霞公主有何
种的印象呢？
LONG
             );
    set("exits",([
        "south":CITY"inhouse2"]) );
    set("light",1);
    set("objects",([
        "aiga":TMOB"aiga"]) );
    reset();
}

void init()
{
    add_action("prevent_quit","quit");
}

int prevent_quit()
{
   object who;
   who = this_player();
   
   if( !who->query_temp("luoky_killer") ) return 0; 
    tell_object(who,"阿重霞奸笑道：杀了人家的宠物，想逃到那去？\n");
    tell_room( environment(who),
    who->query("c_name")+" 居然想畏罪潜逃，但被阿重霞阻止了！！\n"
    ,who );
    return 1;
}
