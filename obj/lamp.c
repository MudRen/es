
#include <mudlib.h>
inherit OBJECT;

void create()     
{
	set_name( "lamp", "油灯" );
	set("short", "@@query_short");
	set("long", "@@query_long");
	set( "unit", "盏" );
	set("weight", 40);
	set("value", ({ 20, "silver" }));
	set("fuel", 1500);  // fuel is measured in seconds
}


void init()
{
	add_action("light_t", "light");
	add_action("light_t", "ignite");
	add_action("extinguish_t", "extinguish");
	add_action("extinguish_t", "unlight");
}

int light_t(string str)
{
	if(!id(str)) return 0;
	if(!query("fuel"))
		return notify_fail("这盏油灯的灯油已经烧完了。\n");

	if(query("light")) 
		return notify_fail("这盏油灯已经点著了。\n");

	write( "你将油灯点亮。\n");
	set("light", 1);
	call_out("burn_out", query("fuel"));
	return 1;
}

int extinguish_t(string str)
{
	if(!id(str)) return 0;
	if(!query("fuel"))
		return notify_fail("太迟了，灯油已经烧完了。\n");

	if(!query("light"))
		return notify_fail("这盏油灯还没有点著，如何熄灭？\n");

	write("你将油灯熄灭。\n");
	set("light", 0);
	set("fuel", remove_call_out("burn_out"));
	return 1;
}

void burn_out()
{
	object owner;

	owner = environment(this_object());
	if( living(owner) )
		tell_object( owner,
			"你的油灯暗了下来，熄掉了。\n");

	set ("value", ({ 1, "silver" }));
	set ("fuel", 0);
	set ("light", 0);
}
/*
string query_short()
{
	if(query("fuel"))
		return "a lamp" + (query("light") ? " (lit)" : "");
	return "a lmap";
}
*/

string query_short()
{
	if(query("fuel"))
		return "油灯" + (query("light") ? " (亮著)" : "");
	return "油灯";
}

/*
string query_long()
{
	if(query("fuel"))
		return "It is a light source.\n" +
			(query("light") ? "It is lit.\n" : "It is not lit.\n");
	return "It used to be a light source.\n";
}
*/

string query_long()
{
	if(query("fuel"))
		return "油灯是一种常见的照明用具，\n" +
			(query("light") ? "这盏油灯是点著的，你可以熄灭(unlight)它。\n"
			: "你可以把它点燃(light)使用。\n");
	return "这盏油灯的灯油已经用光了。\n";
}
