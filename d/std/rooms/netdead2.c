// The Netdead Room, clooect all users who are net-dead, 
// will clean up every 30 mins
// created by Kyoko, 5-11-1994.

#include <mudlib.h>

inherit ROOM;

string *where = ({ "/d/noden/12,3.noden","/d/noden/17,8.noden",
		"/d/noden/2,15.noden","/d/eastland/9,9.east",
		"/d/eastland/7,17.east","/d/deathland/city/c5"
		}) ;
void create()
{
	::create();
	set_short("时间的缝隙" );
	set_long(
		"你现在身处於时间的缝隙，举目所及是灿烂炫目的七彩光芒，\n"
		"空间中矗立著无数的门(door)，据说可以通到世界各地。\n"
	);
	set("light", 1);
    set("c_item_desc",(["door":
	"这是一些泛著七彩光芒的门，你可以挑一扇进去(enter)看看。\n"
     ]));
}

void init() 
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	string move_to;
	int hp;
        if( !arg || arg!="door" )
            return notify_fail("进入哪里？\n" );
	write("你挑了一扇门走进去，突然，脚下一个踩空....\n" );
	tell_room( this_object(),
            this_player()->query("c_name") + "走进一扇门里，消失了...\n",
                this_player() );
	move_to = where[random(sizeof(where))];
	this_player()->move_player( move_to, "SNEAK" );
	write("你碰～的一声跌在地上，摔得屁股痛死了 ...\n");
	this_player()->add("hit_points",-(int)this_player()->query("hit_points")/10);
	tell_object(this_player(),sprintf("( 你%s )\n",(string)"/adm/daemons/statsd"->status_string(this_player())));
	tell_room( move_to ,
            this_player()->query("c_name") + "咻～～的一声掉了下来，摔得四脚朝天。\n",
                this_player() );
        return 1;
}

int receive_object(object arg)
{
	string msg ;
	object* all_inv;
	if(living(arg)) return 1 ;    
	if (base_name(arg)=="/std/statue") return 1;
	tell_room(environment(this_player()),
              arg->query("c_name")+"被一个黑洞吞噬，瞬间就消失了。\n");
	all_inv=all_inventory(arg);
	all_inv->remove();
	arg->remove();
	return 0;
}
