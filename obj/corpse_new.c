// corpse.c
// Real old. Probably came with the mudlib.n, and probably took some
// substantial hacking at TMI-1, though no one put a header on saying so.
// Converted to 0.9.0 by Mobydick@TMI-2, 9-22-92, who added this header.

#include <mudlib.h>

inherit CONTAINER;

#define DECAY_TIME 100
#define MAX_DECAY    4

string name, c_name;
int decay;

void prevent_insert()
{
   write("尸体太大了!!\n");
   return;
}

void create()
{
	::create();
	name = "someone";
	c_name = "某人";
	decay = MAX_DECAY;

	set("weight", 600);
	set_short( "@@query_short" );
	set("unit", "具" );
	set("max_load", 400);
	set("prevent_insert", 1);
	set("id", ({ "corpse", "remains", "body", "dead body" }));
}

void set_name(string str, string str2)
{
	name = str;
	c_name = str2;

	::set_name( "corpse", "尸体" );
	if( name )  name = capitalize(name);
	set_open_long(sprintf("这是%s(%s)的遗体。\n", c_name, name));
	set("id", ({ "corpse", "remains", "body", "dead body",
		sprintf("corpse of %s", name) }) );
	call_out("decay", DECAY_TIME);
}
 
void decay()
{
	decay -= 1;
	switch( decay ) {
		case 0: ::remove(); return;
		case 1: call_out("decay", 20); return;
		case 2: ::set_name("bone", "骸骨");
				set_open_long("一具骸骨, 已分不清是哪一个可怜人的遗骸。\n");
				set("id", ({ "bone", "corpse", "remains", }));
				call_out("decay", 30);
				return;
		case 3: call_out("decay", 50); return;
		default: call_out("decay", 10); return;
	}
}

int can_put_and_get()
{
	return 1;
}
 
string query_short()
{
	switch( decay ) {
		case 1: return "一堆枯骨(bones)";
		case 2: return "一具骨骸(skelton)";
		case 3: return "一具腐烂的尸体(dead body)";
		case 4: return sprintf("一具%s(%s)的尸体(corpse)", c_name, name);
		default: return "一具尸体";
	}
}
