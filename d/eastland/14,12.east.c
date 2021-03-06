
#include <mudlib.h>

inherit ROOM;

int bushes = 1;

void create()
{
	::create();
   set_short("山丘");
	set_long( @LONG_DESCRIPTION
你正走在一由一些低矮山丘组成的丘陵地上，这里的地势起伏并
不很大，青黄交错的短草皮覆盖\著举目所及的山丘，几株大树(tree)
散布在山坡上。
LONG_DESCRIPTION
	);

	set_outside( "noden" );
	set( "exits", ([ 
          "east" : "/d/eastland/15,12.east" ]) );
   set( "original", "/d/eastland/14,12" );
	set( "virtual_server", "/d/eastland/virtual/east_server" );
   set( "x_coordinate", 14 );
   set( "y_coordinate", 12 );
   set( "c_item_desc", ([
        "tree" : "几株疏疏落落的大树。\n",
        "root" : "@@root_stat" ]) );
   set( "search_desc", ([
        "tree" : "你仔细地搜找这些树木, 发现其中有株白杨木的树根(root)有点奇特。\n",
        "root" : "@@search_root" ]) );
	reset();
}

void init()
{
   add_action( "push_bushes", "push" );
}

int push_bushes(string arg)
{
   if( !arg || arg != "bushes" )
   return notify_fail( "你把手往前虚推了几下。\n" );
   write( "你把草丛拨开。\n" );
   bushes = 0;
   return 1;
}

string search_root()
{
   if( !bushes ) {
   this_object()->set("exits/hole","/d/eastland/ianyeu/hole");
     return "当你仔细地搜寻草丛之後的树根时, 竟发现一个巢穴(hole)!\n";
   }
   return "你仔细地搜找树根, 但是草丛(bushes)太多了。\n"
          "或许\你应该先把它们推开(push)。\n";
}

string root_stat()
{
   if( !bushes )
   return "普通的树根, 但是你看到被拨开的草丛後似乎有点古怪。\n";
   else return "普通的树根。\n";
}

void reset()
{
   delete("exits/hole");
   ::reset();
}
