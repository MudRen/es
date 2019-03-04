#include <mudlib.h>
inherit CONTAINER ;

#define DECAY_TIME 100

string name, c_name;
int decay;

void prevent_insert()
{
   write( "The blood is too dirty.\n" );
   return;
}

void create()
{
	::create();
	decay = 2;
        name = "blood";
        c_name = "Ѫˮ";
	::set_name( name, c_name );
//        set_open_long("This is a pool of blood.\n");
        set_c_open_long("����һ̲��Ѫˮ��\n" );
	set ("weight", 100);
	set_short( "@@query_short", "@@query_c_short" );
	set ("unit", "̲" );
	set ("max_load", 400);
	set ("prevent_insert", 1);
	set ("id", ({ "blood",  "dead body",
		  }) );

        call_out("decay", 15);
}

 
void decay() {
 
   decay -= 1;
 
   if(decay > 0) {
      call_out("decay", 20);
      return;
   }
   remove() ;
}
 
int can_put_and_get() { return 1; }
 
string query_short()
{
   if(decay == 2)
      return "a pool of blood ";
   else
      return "somewhat decayed remains of blood";
}

string query_c_short()
{
   if(decay == 2)
      return "һ̲Ѫˮ";
   else
      return "һĨѪ��";
}

