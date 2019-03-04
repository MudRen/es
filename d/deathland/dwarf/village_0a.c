
#include "../echobomber.h"

inherit ROOM;

void create()
{
  ::create();
  set_short("the secret hole","秘密洞穴");
  set_long(@Long
Long
,@CLong
一个很奇怪的场所.到处都是一些杂乱无章的符号(sign),似乎这里的主人是个疯狂的人
CLong
);
set( "c_item_desc",([
     "sign":"一种很奇怪的符号,似乎是一种文字,但是你无法了解他.\n"
     ]) );
  
set( "exits",([
             "out":Deathland"/dwarf/village_09",
             "north":Deathland"/dwarf/village_0b",
             ]));

set ( "pre_exit_func",([
      "north":"to_north",
      ]) );
set( "objects",([
     "assassin":Monster"/assassin01",
    ]) );
reset();
}

int to_north()
{
    if (!present("assassin"))
      return 0;
    else 
     write("幻影杀手挡住了你的去路.\n");
     return 1; 
}

