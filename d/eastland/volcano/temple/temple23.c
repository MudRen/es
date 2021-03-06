#include "../oldcat.h"

inherit ROOM;

int be_get1;
void create()
{
	::create();
        set_short("後院");
	set_long( 
@LONG_DESCRIPTION
这里是神殿後院，一小块地上种著各种不同的蔬菜(vegestable)，中间一条小
径可通往後殿，你还看到有一口井(well)。
LONG_DESCRIPTION
	);

set( "exits", ([
     "west": OTEMP"temple13",
     "southeast":OTEMP"temple25"
     ]) );

set("item_desc",([
    "vegestable":"这一片蔬菜园是神殿里的人种的，使他们可以自给自足。\n",
    "well":@Well
一个已经乾\枯\的\水井，你看到井底连一滴水都没有，很明显的，这口井已经废弃
很久了。
Well
   ]) );
set("search_desc",([
    "vegestable":"@@to_search_vegestable",
    ]) );
set_outside("eastland");
reset();
}

string to_search_vegestable()
{
  string str;
  object ob;

  if(be_get1==2)
    return "你没有找到任何有用的东西。\n";

  str="\n你在菜园子里，找到一个浇菜用的大桶子。\n";
  ob=new(OOBJ"bucket");
  ob->move(this_player());
  be_get1++;
  return str;
}

void reset()
{
  ::reset();
  be_get1=0;
}
