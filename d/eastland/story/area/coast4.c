#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("丛林");
	set_long(@LONG
你来到了一处热带丛林区，四周满是高及头顶的蕨类植物，这里的热气快要使
得你昏倒在地，更兼藏身在植物里的小虫，不住地叮著你的全身，令你难过已极！
或许，先找个清凉的地方休息一下，再继续走，会好过一点。忽然，不远的东边传
来阵阵野兽的叫声，那声音，骇人已极，你最好不要往那边走去，以免发生危险。
LONG
	);
	set("exits", ([ 
       	    "east" : SAREA"coast5", 
            "west" : SAREA"coast3",
           "south" : SAREA"coast6"
        ]) );
        set("pre_exit_func",([                                                  
	    "east" : "do_east",
	   "west"  : "do_west",
	   "south" : "do_south"
	]) );
	reset();
}
int do_east()
{
     object player;
     player=this_player();
     if ( player->query_temp("east_times")<2+random(6) ) {
         player->add_temp("east_times",1);
         player->move_player(SAREA"coast4","SNEAK");
         return 1;     
     }    
     player->set_temp("can_south",1);
     player->delete_temp("east_times");
     return 0;
}
int do_west()
{
    this_player()->delete_temp("east_times");
    this_player()->delete_temp("can_south");
    return 0;
}
int do_south()
{
    object player;
    player=this_player();
    if ( !player->query_temp("can_south") ) {
        player->move_player(SAREA"coast4","SNEAK");
        player->delete_temp("east_times");
        return 1;
    }
    player->delete_temp("can_south");
    player->delete_temp("east_times");
    return 0;
}