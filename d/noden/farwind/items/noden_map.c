#include <mudlib.h>
inherit OBJECT;
inherit MAP;

void create()
{
         seteuid(getuid());
	set_name( "map", "地图" );
	set_short( "诺顿王国地图" );
	set_long(@CLONG
这是诺顿王国的全图，你可以 read map 看地图内容，或用
read legend 看地图上符号所代表的意义。
CLONG
	);
	set_size( 21, 21 );
	set( "prevent_get", 1 );
	set_center_coordinate( 10, 10, "/d/noden/virtual/noden_server");
}
