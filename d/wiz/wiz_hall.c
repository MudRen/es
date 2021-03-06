#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "巫师大厅" );
	set_long(
		"你现在正站在巫师领域的大厅之中，这个大厅是用某种白中带著淡蓝色纹\n"
	"路的石材建成的，一些绿色的植物和不知名的花卉装饰著大厅四周的圆柱。北\n"
	"边是著名的「巫师学院」，西边是传说中的「世界广场」，往南则是巫师们办\n"
	"公的所在地。东边的墙上有一面巨大的镜子。\n"
	);
	set( "light", 1 );
	set( "pre_exit_func", ([
		"east" : "to_farwind"
	]) );
	set( "exits", ([
		"east"  : "/d/adventurer/hall/adv_guild",
		"south" : "/d/wiz/wiz_office",
        ]) );
}

int to_farwind()
{
		write("你穿过镜子，进入冒险者公会。\n");
	return 0;
}
