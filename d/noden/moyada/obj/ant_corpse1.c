// corpse.c
// Real old. Probably came with the mudlib.n, and probably took some
// substantial hacking at TMI-1, though no one put a header on saying so.
// Converted to 0.9.0 by Mobydick@TMI-2, 9-22-92, who added this header.

#include <mudlib.h>
inherit CONTAINER;

#define DECAY_TIME 200

int decay;

void prevent_insert()
{
   write( "The corpse is too big.\n" );
   return;
}

void create()
{
	::create();
	decay = 2;
	set ("weight", 100);
	set ("type", "ant");
	set_name( "corpse of ant", "���ϵ�ʬ��" );
	set_short( "@@query_c_short" );
	set ("unit", "��" );
	set ("max_load", 400);
	set ("prevent_insert", 1);
	set ("id", ({ "corpse", "remains", "body", "dead body", }) );
    add("id", ({ "corpse", "remains", "body", "dead body", }) );
    call_out("decay", DECAY_TIME);
}
 
void decay()
{
   decay -= 1;
   if(decay > 0) {
      call_out("decay", 50);
      return;
   }
   remove() ;
}
 
int can_put_and_get() { return 1; }
 
//string query_short()
//{
//   if(decay == 2)
//      return "corpse of ant";
//   else
//      return "somewhat decayed remains of ant";
//}

string query_c_short()
{
   if(decay == 2)
      return "���ϵ�ʬ��";
   else
      return "���ϵĹǺ�";
}
