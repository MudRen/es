// corpse.c
// Real old. Probably came with the mudlib.n, and probably took some
// substantial hacking at TMI-1, though no one put a header on saying so.
// Converted to 0.9.0 by Mobydick@TMI-2, 9-22-92, who added this header.

#include <mudlib.h>

inherit CONTAINER;

#define DECAY_TIME 200
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
	set("id", ({ "corpse", "remains", "body", "dead body","bone" }));
}
string query_short()
{
        switch( decay ) {
                case 1: return "�ݹ�";
                case 2: return "����";
                case 3: return "���õ�ʬ��";
                case 4: return sprintf("%s��ʬ��", c_name);
                default: return "ʬ��";
	}
}
void set_name(string str, string str2)
{
	name = str;
	c_name = str2;

	::set_name( "corpse", "ʬ��" );
	if( name )  name = capitalize(name);
        set_c_open_long(sprintf("����%s�����塣\n", c_name));
	set("id", ({ "corpse", "remains", "body", "dead body", "bone",
		sprintf("corpse of %s", name) }) );
	call_out("decay", DECAY_TIME,this_object() );
}
 
void decay(object me)
{
    
	decay -= 1;
	set_c_open_long( query_short()+"\n");
	switch( decay ) {
		case 0: { 
		           object *obs;
		           int i;
		           obs=all_inventory(me);
		           for (i=sizeof(obs)-1; i >=0 ; i--) 
		             obs[i]->remove();
		           me->remove(); 
		           return;
		        } 
		case 1: call_out("decay", 80,me); return;
		case 2: ::set_name("bone", "����");
				call_out("decay", 80,me);
				return;
		case 3: call_out("decay", 80,me); return;
		default: { decay = 1;
		           call_out("decay", 40,me); return;
		         }  
	}
}

int can_put_and_get()
{
	return 1;
}
 

