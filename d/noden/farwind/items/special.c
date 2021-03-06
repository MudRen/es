#include <mudlib.h>

inherit OBJECT;

void create(){

	set_name("special","特调大补酒");
	add( "id" , ({ "special" }) );
	set_short( "特调大补酒" );
	set_long( "特调大补酒，限当场喝！\n" );
   	set("unit","杯");
   	set("weight", 15);
   	set("value",({100, "silver"}) );
	set("drink",10);
	call_out("drink_it", query("drink"), this_object() );
}

void drink_it(object who)
{
	object owner;
	owner = environment(who);
	if( owner && living(owner) ) 
	{
		tell_object(owner,
			"你喝下一杯特调大补酒。感到精神好了一些。\n"
		);
		tell_room( environment(owner), 
			owner->query("c_name")+"喝下一杯特调大补酒，精神看起来好了一些!!\n",
			owner );

		owner->receive_healing(15);
	}
	remove();
}
	
