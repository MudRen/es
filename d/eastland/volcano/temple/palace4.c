#include <daemons.h>
#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

int min,hour,day,year;
string month;

void create()
{
	::create();
	set_short( "走廊" );
	set_long(
@LONG
你正漫步在井龙宫的走廊，一盏盏琉璃灯火悬在走廊的两旁，在这里你做什麽事
都得特别小心，否则会发生什麽事只有天知道。
你注意到在你的西边有一扇红宝石大门(door)。
LONG
	);
	set( "exits", ([
             "north" : OTEMP"palace6",
             "west" : OTEMP"palace4",
	     "east" : OTEMP"palace3",
	]) );
        set("item_desc",([
            "door":
"一扇红宝石大门，门上面有块圆形水晶(crystal)，想打开这扇门必需看准时间。\n",
            "crystal":"@@look_crystal",
            ]) );
         set("pre_exit_func",([
             "west":"to_west"
             ]) );
         set("light",1);
         reset(); 
}

int to_west()
{
  printf("\n门上的水晶发出一道红光射中你的身体，把你从门边推开。\n");
  return 0;
}

string look_crystal()
{
  string str;

  sscanf(WEATHER_D->query_game_time(),"%d:%d, %s %d, Year %d",hour,min,month,day,year);
//  printf("%d %d\n",hour,min);
  if ((((min-30)>hour) && (hour<12)) || (((min-15)>hour) && (hour>12)) )
    this_player()->set_temp("ruby_door",1);
  else
    this_player()->delete_temp("ruby_door");
  str="\n你向水晶望去，清楚的从里面看到一排字 ： \n"+ WEATHER_D->query_c_game_time()+"\n\n";
  return str;
}

void init()
{
  add_action("do_touch","touch");
}

int do_touch(string arg)
{
  if (!arg || arg!="crystal" )
    return 1;
  if (this_player()->query_temp("ruby_door")) {
    printf("\n水晶发出一道柔和的白光将你胧罩，\n");
    printf("\n你定下神来，发现自己被四周刺眼的亮光所包围。\n");
    this_player()->move_player(OTEMP"palace9","SNEAK");
    this_player()->delete_temp("ruby_door");
    return 1; }
  printf("\n水晶嗡嗡作响：你来得不是时候。\n");
  return 1;
}
