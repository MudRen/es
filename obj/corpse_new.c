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
   write("ʬ��̫����!!\n");
   return;
}

void create()
{
	::create();
	name = "someone";
	c_name = "ĳ��";
	decay = MAX_DECAY;

	set("weight", 600);
	set_short( "@@query_short" );
	set("unit", "��" );
	set("max_load", 400);
	set("prevent_insert", 1);
	set("id", ({ "corpse", "remains", "body", "dead body" }));
}

void set_name(string str, string str2)
{
	name = str;
	c_name = str2;

	::set_name( "corpse", "ʬ��" );
	if( name )  name = capitalize(name);
	set_open_long(sprintf("����%s(%s)�����塣\n", c_name, name));
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
		case 2: ::set_name("bone", "����");
				set_open_long("һ�ߺ���, �ѷֲ�������һ�������˵��ź���\n");
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
		case 1: return "һ�ѿݹ�(bones)";
		case 2: return "һ�߹Ǻ�(skelton)";
		case 3: return "һ�߸��õ�ʬ��(dead body)";
		case 4: return sprintf("һ��%s(%s)��ʬ��(corpse)", c_name, name);
		default: return "һ��ʬ��";
	}
}
