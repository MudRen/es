#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "silver_chocolate", "银色巧克力" );
	add( "id", ({ "chocolate" }) );
	set_short( "银色巧克力" );
	set_long(
		"这是一个包著火山豆的巧克力，你可以□□看(taste)。\n"
	);
	set( "type", "misc" );
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
  add_action("do_eat","taste");
}

int do_eat(string arg)
{
   int sp,spmax;
   if(!arg || arg!="chocolate")
   { write("你要吃什麽？\n");
     return 1;
   };

   write("你吃了一块包著火山豆的巧克力，浓浓的巧克力香混著火山豆独特的味道。\n");
   write("你感到说不出的舒服，真想再吃一块。\n");
   sp=this_player()->query("spell_points");
   spmax=this_player()->query("max_sp");
   if (spmax<(sp+10))
     this_player()->set("spell_points",spmax);
   else
     this_player()->set("spell_points",sp+5);
   this_object()->remove();
   return 1;
}
