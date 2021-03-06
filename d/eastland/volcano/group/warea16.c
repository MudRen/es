#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮灵族部落");
	set_long(
@LONG_DESCRIPTION
这里是矮灵族部落群，西边可以通到出口，东边可通到广场，这里的建筑物大都是石
造的，少数人住帐蓬，地上用很多石板铺成的路贯穿整个部落，整个部落给人的感觉
是非常宁静且安详的，由於火山已经有很多年没有爆发了，因此新一代的族人也慢慢
的就淡忘了此事。一座构筑宏伟的神殿(temple)矗立在这儿。
LONG_DESCRIPTION
	);
set("item_desc", ([
    "temple" : "一座巨大的矮灵族神殿，这座神殿供奉著他们最崇拜的神，火神。\n",
    ]) );
set( "exits", ([ 
     "west" : OGROUP"warea11" ]) );
set_outside("eastland");
reset();
}

void init()
{
   add_action("do_enter","enter");
}

int do_enter(string arg)
{
  if (!arg || arg!="temple" ) {
    write("你要进去那里？\n");
    return 1;
  }
  tell_object(this_player(),"你走进这座神殿中。\n");
  tell_room(this_object(),"你见到"+this_player()->query("c_name")+"走进神殿内。\n",this_player());
  this_player()->move_player(OTEMP"temple1","SNEAK");
  return 1;
}
