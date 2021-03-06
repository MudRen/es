#include "../oldcat.h"

inherit ROOM;

int east_totem,west_totem,south_totem,north_totem;
int can_search_fire;

void create()
{
	::create();
    set_short("矮灵族部落广场");
	set_long( 
@LONG_DESCRIPTION
这里是矮灵族部落广场，每当有庆典或是祭典，所有的矮灵族人都会在这里聚会，广
场中央是一堆用石头围起来的营火区，熊熊烈火正在那里燃烧，广场东西南北还有四
个图腾，图腾上刻著一些怪物的头，或狰狞、或严肃、或闭眼、或狂笑，一截截的图
腾(totem)显示矮灵族丰富的想像力及表示他们心里对自然界一些景像的畏惧。
LONG_DESCRIPTION
	);
set( "exits", ([
     "south" : OGROUP"warea4",
     "north" : OGROUP"warea6",
     "east" : OGROUP"warea10" ]) );
set( "item_desc", ([
     "totem":"这四个图腾是矮灵族的艺术结晶，你注意到每个图腾怪物的头似乎可以转动(turn)。\n",
     "fire" : "@@look_fire",
     "tunnel" : "@@look_tunnel",
     ]) );
set("search_desc", ([
    "fire":"@@search_fire",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_turn","turn");
  add_action("do_enter","enter");
}

/* <east totem>=west, <south totem>=south, <west totem>=west, <north totem>=east
   then can see secret tunnel. */

string search_fire()
{ 
  string str;

  if (east_totem==3 && south_totem==2 && west_totem==3 && north_totem==1) {
    this_player()->set_temp("fire/check",1);
    return "在烈火熄了之後，你搜寻中央营地，发现一条似是秘道(tunnel)的入口。\n";
  }
  return "在熊熊烈火之下，做什麽动作都是无义意的。\n";
}

string look_fire()
{
  if (east_totem==3 && south_totem==2 && west_totem==3 && north_totem==1) {
     return "你发现原来中央的熊熊烈火突然消失的无影无踪。\n";
  }
  return "一片熊熊烈火正在中央营地日以继夜的燃烧著。\n";
}

string look_tunnel()
{
  if(this_player()->query_temp("fire/check"))
    return "一条似是秘道的入口，从入口看进去，黑漆漆的。\n";
  return "你要看什麽?\n";
}

int do_enter(string arg)
{
  if (!arg || arg!="tunnel")
    return 1;

  if (east_totem==3 && south_totem==2 && west_totem==3 && north_totem==1) {
   if (this_player()->query_temp("fire/check")) {
    east_totem=1;
    south_totem=1;
    west_totem=1;
    north_totem=1;
    write("\n你走进秘道。\n\n");
    this_player()->move_player(OGROUP"tunnel1","SNEAK");
    return 1;
   }
  }

  return 1;
}

int do_turn(string arg)
{
  string str1;

  if (!arg || arg=="")
    return notify_fail("The syntax: turn <direction> totem\n");

  if (sscanf(arg, "%s totem",str1) == 1) {
    switch(str1) {
    case "east" : switch(east_totem) {
                  case 4 :
                        write("你将东方图腾的怪物头转向东方。\n");
                        east_totem=1;
                        break;
                  case 2 :
                        write("你将东方图腾的怪物头转向西方。\n");
                        east_totem=3;
                        break;
                  case 1 :
                        write("你将东方图腾的怪物头转向南方。\n");
                        east_totem=2;
                        break;
                  case 3 :
                        write("你将东方图腾的怪物头转向北方。\n");
                        east_totem=4;
                        break;
                  default:
                    return 1;
                  };
         break;
    case "west" : switch(west_totem) {
                  case 4 :
                        write("你将西方图腾的怪物头转向东方。\n");
                        west_totem=1;
                        break;
                  case 2 :
                        write("你将西方图腾的怪物头转向西方。\n");
                        west_totem=3;
                        break;
                  case 1 :
                        write("你将西方图腾的怪物头转向南方。\n");
                        west_totem=2;
                        break;
                  case 3 :
                        write("你将西方图腾的怪物头转向北方。\n");
                        west_totem=4;
                        break;
                  default:
                    return 1;
                  };
         break;
    case "south" : switch(south_totem) {
                  case 4 :
                        write("你将南方图腾的怪物头转向东方。\n");
                        south_totem=1;
                        break;
                  case 2 :
                        write("你将南方图腾的怪物头转向西方。\n");
                        south_totem=3;
                        break;
                  case 1 :
                        write("你将南方图腾的怪物头转向南方。\n");
                        south_totem=2;
                        break;
                  case 3 :
                        write("你将南方图腾的怪物头转向北方。\n");
                        south_totem=4;
                        break;
                  default:
                    return 1;
                  };
         break;
    case "north" : switch(north_totem) {
                  case 4 :
                        write("你将北方图腾的怪物头转向东方。\n");
                        north_totem=1;
                        break;
                  case 2 :
                        write("你将北方图腾的怪物头转向西方。\n");
                        north_totem=3;
                        break;
                  case 1 :
                        write("你将北方图腾的怪物头转向南方。\n");
                        north_totem=2;
                        break;
                  case 3 :
                        write("你将北方图腾的怪物头转向北方。\n");
                        north_totem=4;
                        break;
                  default:
                    return 1;
                  };
          break;
    default :
          return notify_fail("The syntax: turn <direction> totem\n");
    }; 
    return 1;
  }
  return notify_fail("The syntax: turn <direction> totem\n");
}

void reset()
{
  ::reset();
  east_totem=1;
  west_totem=1;
  south_totem=1;
  north_totem=1;
  can_search_fire=0;
}
