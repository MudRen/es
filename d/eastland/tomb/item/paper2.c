#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name("note","短函");
	set_short("一封短函");
	set_long(
		"一封短函，上面写著几行字。\n"
	);
	set("no_sale",1);
	set( "unit", "封");
	set("weight", 2);
	set("value", ({ 5, "silver" }));
}

void init()
{
	add_action("read_note","read");
}

int read_note(string str)
{
    object ob;
    if ( !str || str != "note" ) return 0;
    else {
      ob = environment(this_object());
      if ( ob != this_player() ) 
        return 0;
      else 
        {
          write("谢谢你，有缘人。\n"
          	"我无以回报，只能送你这颗珠子，它是进入陵墓的关键。\n" );
          return 1;      
        }
    }
}
