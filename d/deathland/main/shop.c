#include "../echobomber.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "阴暗的商店" );
	set_long( @C_LONG
当你走进这个帐蓬里,你发觉这里应该是一间商店,然而你却看不到人,因为店主整
个人藏在柜台的後面.只有他看得到你而你完全看不到他.而墙上点燃著一把火炬,微弱
的火光更使这里显得恐怖.让人感觉到你好像进入黑店一样.
C_LONG
);
	set( "exits", ([ 
	  "out" : Deathland"/main/d11", 
	]) );
	::reset();
}
void init()
{
   ::init();
   add_action("to_sell","sell");
}

int to_sell(string str)
{
    write("老板露出邪恶的笑容,说: 到这里来卖东西,嗯......\n");
    if ( (int)this_player()->query("alignment") >= 0 ) {
      write("我想好人应该帮助我这个穷人吧!\n");
	  // rating 1,3 mean 1/3 By Kyoko.
      this_object()->set("rating", ({ 1, 3 }) );
    } else {
      write("邪恶的家伙,我喜欢,但是在商言商,所以...\n");
      this_object()->set("rating", ({ 2, 5 }) );   
    }
    return ::sell(str);
}
