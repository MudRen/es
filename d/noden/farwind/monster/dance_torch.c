#include "../farwind.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(1);
	set_name( "dancing torcher", "跳跳的火把" );
	add( "id", ({ "torcher" }) );
	set_short("跳跳的火把");
	set_long(@CLONG
这是一把奇特的火把，它是艾柏鲁斯年轻时在修行中得到的物品,
颇具灵性的它已经成了艾柏鲁斯的宠物了。
CLONG
               );
   set( "race", "undead" );
	set_natural_armor( 10, 7 );
	set_natural_weapon( 10, 2, 7 );
	set( "unbleeding", 1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
    set( "alt_corpse", "/obj/torch" );
    set_c_verbs(({ "%s用头上的火焰烧%s", "%s用身体撞%s" }));
    set_c_limbs(({ "身体", "头部" }));
    set("c_death_msg","%s突然毫无生气地躺在地上... 不动了。\n");
	set("moving", 1 );
	set("speed", 30 );
	set("patrol", ({ "north", "south", "west", "west", "east", "east",
		"south", "north" }) );
	set_perm_stat( "str", 3 );
	set_perm_stat( "dex", 4 );
	set_skill( "dodge", 40 );
	set( "special_defense", ([ "all": 20 ]) );
   set( "unbleeding", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
}

int stop_attack()
{
   object master, *tmp;

   master = present( "ebbruce", environment() );
   if( !master ) return 0;
   tell_room( environment(),
          "艾柏鲁斯喝道: 竟敢欺负我的宠物! 不要命了?\n" );
   tmp = query_temp( "protectors" );
   if( !tmp || member_array( master, tmp )==-1 ) {
        add_temp( "protectors", ({ master }) );
        master->add_temp( "protectees", ({ this_object() }) );
        }
        tmp = master->query_attackers();
   if( !tmp || member_array( this_player(), tmp )==-1 )
         master->kill_ob( this_player() );
}
