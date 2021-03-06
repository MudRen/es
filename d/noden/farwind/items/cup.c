#include <mudlib.h>

inherit OBJECT;

int filled;

void create()
{
	set_name("cup", "杯子");
	add( "id", ({ "paper cup" }) );
	set_short( "纸杯" );
	set("long","@@query_c_long");
	set( "quest_smith", 1 );
	set( "weight", 3 );
	filled = 0;
}

string query_c_long()
{
	if( filled )
		return "这个杯子装满了清水，但是若不把水喝(drink)掉或倒(pour)掉，\n"
			"这个杯子可能很快会糊掉。\n";
	else
		return  "这个纸杯似乎可以用来装水，你所要做的只是找一处有水的地方\n"
			"用 fill cup 把杯子装满水。\n";
}

int query_filled() { return filled; }

void init()
{
	add_action( "fill_water", "fill" );
	add_action( "drink_water", "drink" );
	add_action( "pour_water", "pour" );
}

int fill_water(string arg)
{
	object env;

	if( !arg || arg!="cup" )
		return notify_fail("用什麽装水？\n");
	if( filled )
		return notify_fail("杯子中已经装满清水了。\n");

	env = environment(this_object());
	if( living(env) ) env = environment(env);

	if( !env->query("water_source") )
		return notify_fail("这里没有水....。\n");

	filled = 1;
	write("你把杯子装满清水。\n");
	call_out("mess_up", 200);
	return 1;
}

int drink_water(string arg)
{

	if( !arg || arg!="cup" )
		return notify_fail("喝什麽？\n");
	if( !filled )
		return notify_fail("杯子是空的。\n");
	filled = 0;
	write("你把纸杯中的水喝光了。\n");
	return 1;
}

int pour_water(string arg)
{
	if( !arg || arg!="cup" )
		return notify_fail("倒掉什麽？\n");
	if( !filled )
		return notify_fail("杯子是空的。\n");
	filled = 0;
	write("你把纸杯中的水倒光了。\n");
	return 1;
}

void mess_up()
{
	object owner;

	owner = environment(this_object());
	if( living(owner) ) {
	tell_object(owner, "你的纸杯糊掉了，变成一团湿纸团，你随手将它扔了。\n");
	}
	remove();
	return;
}
