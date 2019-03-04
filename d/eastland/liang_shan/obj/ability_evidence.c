#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "evidence of ability", "нДруж╓цВйИ" );
	add( "id", ({ "evidence" }) );
	set_short( "evdence of ability", "нДруж╓цВйИ" );
	set_long(
		".\n",
		"р╩уелл╫П╣д╨эф╞аа╣дж╫ё╛иоцФп╢акр╩п╘вжё╛╩РпМ\дЦ©ирт\n"
		"╤а╤а©╢иоцФп╢п╘й╡ВА║ё\n"
	);
	set( "unit", "уе" );
	set( "weight", 10 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}
void init()
{
//      set("owner",environment(this_object()));
        add_action( "do_read", "read");
}

int do_read(string str)
{
     object owner;
     owner = query("owner");
     if (!str || str != "evidence" )
     return notify_fail(
          "╤ай╡ВА?\n");
          tell_object( this_player(),"[1;33mиоцФсц╨эуШфК╣дп║©╛п╢жЬ:   \n" 
          "вхж╓цВ"+owner->query("c_name")+"нДруря╢О╪вжжи╫тТль╣хуГйт╠Йв╪ё╛\n"
          "гКв╪сХ╡н╪са╨и╫и╫тТппап║ё\n\n"
          "╪Шж╓хк: иЯ╩З╬Эй╕жЛнД[0m \n");
          return 1;
}
