#include <mudlib.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "飘雪洞天" );
	set_long(
		"这是一间新盖好的工作室，它目前空荡荡地没有任何东西。也许你第一件\n"
	"要做的就是在这里加一些东西。\n"
	);
        set( "light",1 );
	set( "exits", ([
		"adv" : "/d/adventurer/hall/adv_guild",
		"scholar" : "/d/scholar/scholar/scholar_guild",
	]) );
        set( "objects", ([
          "icy" : "/u/s/snow/obj/icy.c",
          "shoe" : "/u/s/snow/obj/shoe.c",
          "dress" : "/u/s/snow/obj/dress.c"
        ]) );
        reset();
}
void init()
{
        add_action("to_rest","rest");
}
int to_rest()
{
	object me;
	me = this_player();
	me->set("max_hp",3000);
	me->set("hit_points",3000);
	me->set("spell_points",320);
	me->set("force_points",3000);
	me->set("talk_points",600);
        write ("一股寒气围绕着你,你觉得浑身舒畅.\n");
	return 1;
}                                        
