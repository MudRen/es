#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("丛林");
	set_long(@LONG
你来到了一处热带丛林区，四周满是高及头顶的蕨类植物，这里的热气快要使
得你昏倒在地，更兼藏身在植物里的小虫，不住地叮著你的全身，令你难过已极！
站在这里，不时传来阵阵海浪的声音，原来在你西边是一处白沙滩。
LONG
	);
	set( "exit_suppress", ({
	   "south"}) );
	set("exits", ([ 
       	    "east" : SAREA"coast4", 
            "west" : SAREA"coast1",
           "south" : SAREA"coast7" 
        ]) );
	set("objects", ([
           "insect#1" : SMOB"insect1",
	   "insect#2" : SMOB"insect1",
           "insect#3" : SMOB"insect1"
	]) );
	reset();
}
void init()
{
    add_action("do_search","search");
}
int do_search( string arg )
{
    write("你找了找发现在南边(south)似乎有条通道！\n");
    return 1;
}