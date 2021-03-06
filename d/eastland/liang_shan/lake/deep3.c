#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("湖中");
	set_long( @C_LONG_DESCRIPTION
这里是湖中的深水区域，除了打鱼的鱼夫偶而会来到此处外，一般的冒险者由
於游泳技术不佳，很少来到此处。形形色色的鱼儿，因为没有人为的干扰，正在水
中快乐的游来游去。
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"down" : TROOM"underwater3", 
		"south" : TROOM"deep5",
		"east" : TROOM"shallow3", 
	        "west" : TROOM"whirl1",
	        "north" : TROOM"shallow1"]));
	set( "pre_exit_func",([
	        "south":"check_deep",
	        "east":"check_shallow",
	        "west":"check_whirl",
	        "north" :"check_shallow"
	        ]));
	reset();
}
int check_deep()
{    
    if ((int)this_player()->query_skill("swimming")-random(15)<40){
    write (
    "你努力地想要游到别处，但是身子却不听使唤的向下沉去.......\n");
    this_player()->move_player(TROOM"underwater3","SNEAK");
  return 1;
  }
    else return 0;
}
int check_shallow()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "你努力的想游到别处，但你发现身体一动也不动.....\n");
  return 1;
    }
    else return 0;
}
 int check_whirl()
 {
   int n;
   string place;
   write (
   "突然间，你发现你正游向一个大漩涡，强劲的水流不断的把你扯向漩涡中心。\n"
   "你不断的挣扎...................................\n\n\n\n"
   "你终於精疲力尽，随著漩涡卷入水底，死亡的阴影顿时占据了你的心灵.....\n");
   switch (n=random(3) ){
   case 0: place = "whirl1"; break;
   case 1: place = "whirl2"; break;
   case 2: place = "whirl3"; break;
   }
   this_player()->move_player( TROOM+place,"SNEAK");
   return 1;
 }
