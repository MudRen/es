#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("湖滨");
	set_long( @C_LONG_DESCRIPTION
你来到一片平坦的沙地，柔细的黄沙使得你的身後，留下一行深深的足印，偶尔
清风吹起，湖面泛起阵阵涟漪，不禁令人有出世之想，沙地旁的草丛长满了不知名的
野花。西方有一座简单的碉堡，许\多船只在碉堡前进进出出。
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"east" : TROOM"beach2",
		"west" : TLAND"water_castle.c",
		"south" : TROOM"shallow1" ]) );
	set( "pre_exit_func",([
	        "south":"check_enter"
	        ]));
	reset();
}
int check_enter()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "你走入水中，突然想起你不太会游泳，连忙跑回岸上\n");
    return 1;
    }
    else return 0;
 }   