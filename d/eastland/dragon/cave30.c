#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("花园");
	set_long( @C_LONG_DESCRIPTION
这里是一个花团锦簇的花园，这里有非常多的奇花异草，是郑大户从世界各地移植过
来的，其中有一株数人高的食人树，每天要□其一只大象，也有数株纯黑玫瑰听说是园艺
大师章鱼正心的杰作，这里也有一个喷泉(fountain)。
C_LONG_DESCRIPTION
	);
set("item_desc",([
    "fountain":"这是一个乾枯\的喷泉。\n"]));
	
	set("objects",([
	    "woman1":"/d/noden/nodania/monster/gardener"
	    ]));
	set( "light", 1 );
	set( "exits", ([
	    "west" : Lcave"cave29"
	]) );
	reset();
}

void init()
{
    add_action("do_enter","enter");
 }
 
int do_enter(string arg)
{ 
 if (!arg || arg!="fountain") return 0;
 tell_room(environment(this_player()),
         this_player()->query("c_name")+"进入喷泉中\n",this_player() );
 this_player()->move_player(Lcave"cave31","SNEAK");
 return 1;
 }
