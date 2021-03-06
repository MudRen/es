#include <mudlib.h>

inherit ROOM;
inherit "/d/scholar/train";

void create()
{
	::create();
    set_short("Gonfu room", "功\夫室");
	set_long( @LONG_DESCRIPTION
This is the inner hall of scholar's guild. .
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你在进入了书生公会内部的功\夫室，这里是书生们习武的地方，只有书生
公会的人才能进来，大厅中央有一本记载武功\心法的书(book)。
C_LONG_DESCRIPTION
	);
    set("c_item_desc",([
         "book":@BOOK
书上有写著一些武功\心法如果你想学的话可以用 train <功\夫名称> 学得。

护体神功\ ： 布衣神功\(booyi)
轻功\     ： 天罗步(tanlo)
运功\心法 ： 运功\疗伤(force-heal)    
剑术     ： 无名剑法(unknow)

BOOK
	]));         
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/scholar/scholar/scholar_inner" ]) );
    set_gonfus(([
          "tanlo"        : ({  3 ,  1000 }),
          "force-heal"   : ({  6 ,  3000 }),
          "booyi"        : ({  8,   8000 }),
          "unknow"       : ({ 10 , 15000 }),
	]));
	reset();
}
