#include "../moyada.h"

inherit MONSTER;

void create ()
{
    object shovel;
	::create();
	seteuid( getuid() );
	set_level(8);
	set_name( "worker", "工人" );
	set_short( "修路工人" );
	set_long( @C_LONG
修筑道路的工人, 你看他满头大汗的样子, 不禁想要帮助(help)他。
C_LONG
	);
	set( "alignment", 200 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 17 );
	set_perm_stat( "piety", 7 );
	set_perm_stat( "karma", 10 );
	set ("max_hp", 220);
	set ("hit_points", 220);
	set ("wealth", ([ "silver": 15 ]) );
	set_natural_weapon( 10, 7, 12 );
	set_natural_armor( 25, 5 );
    set ("weight", 750);
    set ("exp_reward",690 );
    set_experience(2000);
    shovel = new(MOYADA"obj/shovel");
    shovel->move(this_object());
    wield_weapon( MOYADA"obj/pick" );
    equip_armor( MOYADA"obj/dirty_shirt" );
    set ("chat_chance", 5);
    set ("chat_output", ({
      "修路工人一边把碎石子铺在地上, 一边用脏毛巾擦汗。\n",
    }) );
}

void init()
{
    add_action( "to_help", "help" );
}

int to_help(string str)
{
   object player;
   if( !str || str != "worker" )
     return notify_fail("帮谁忙呢???\n");
   tell_object( this_player(), 
     "工人说: 谢啦, 听说商店的老板正在找工人, 你可以去试试看。\n" 
     );
   return 1;
}
