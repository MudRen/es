#include <mudlib.h>
#define MIX "/d/healer/mix"
#define MESS_OB "/d/healer/potion/mess"

inherit CONTAINER;

void create()
{
	::create();
	seteuid(getuid());
	set_name( "herb bowl", "药钵" );
	add( "id", ({ "bowl" }) );
	set_short( "an herb bowl", "药钵" );
	set_c_open_long(
		"这是一个行医者用来研磨草药的药钵，将你要研磨的药材放进药钵，然後\n"
		"用 mix 指令即可。\n" );
	set( "weight", 10 );
	set( "value", ({ 100, "silver" }) );
        set( "max_load", 80 ) ;
	set( "weight_apply", 100 );
	set( "prevent_insert", 1 );
	set( "prevent_put_money", 1 );
}

void init()
{
	::init();
	add_action( "do_mix", "mix" );
}

int do_mix(string arg)
{
	object *inv;
	string potion;
	int i,number;
	int weight;
	object the_potion;

	if( arg && !id(arg) ) return 0;
	if( !environment() || environment()!=this_player() ) return 0;
	inv = all_inventory();
	if( !sizeof(inv) ) return notify_fail( "你的药钵里什麽也没有....。\n");
	potion=MIX->mix(this_object());
	weight=query("weight");
	for(i=0; i<sizeof(inv); i++) {
	        weight = weight - (int)(inv[i]->query("weight") );
	        this_player()->add("load",- (int)(inv[i]->query("weight") ) );
		inv[i]->remove();
	}	
	if( potion ) {
	     number=MIX->potion_amount();
	     for (i=0; i < number; i ++) {
	        the_potion = new(potion);
	        weight = weight + the_potion->query("weight");
	        this_player()->add("load",the_potion->query("weight") );
		the_potion->move(this_object());
	     }
		write( "你将药钵里的药材混合磨碎，配成" + the_potion->query("c_name") + "。\n"
	 	     );
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "将药钵里的药材混合磨碎。\n" ,
			this_player() );
		set("weight",weight);	
		return 1;
	} else {
//		the_potion = new(MESS_OB);
//		the_potion->move(this_object());
//	        weight = weight + the_potion->query("weight");
//		this_player()->add("load",the_potion->query("weight"));
		write("你将药钵里的药材混合磨碎......结果变成一团烂泥。\n" );
		write("你叹了一口气, 随手把药钵里的烂泥清掉。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "将药钵里的药材混合磨碎。\n" ,
			this_player() );
		set("weight",weight);	
		return 1;
	}
}
