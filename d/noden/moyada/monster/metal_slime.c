#include "../moyada.h"
inherit MONSTER;

void create ()
{
    object amulet;
	::create();
	seteuid( getuid() );
	set_level(1);
	set_name( "metal slime", "金属史莱姆" );
	add ("id", ({ "slime", }) );
	set_short( "金属史莱姆" );
	set_long( @LONG
金属的软体怪? 好奇怪? 一双圆圆的大眼睛好奇的看著你，看起来好可爱。
LONG
	);
   set( "race", "undead" );
	set( "alignment", 4000 );
    set( "unit", "只" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 1 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 1 );
	set_perm_stat( "piety", 30 );
	set_perm_stat( "karma", 30 );
	set ("max_hp", 5);
	set ("hit_points", 5);
	set_natural_weapon( 15, 3, 6 );
   set_natural_armor( 250, 100 );
	setenv( "C_MIN", "一只$N愉快的跳了过来。");
	setenv( "C_MOUT", "$N高兴著往$D边跳走了。");
   set("unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set ("aim_difficulty", ([ "critical" : 100, "weakest" : 100, ]) );
	set ("special_defense",
        ([ "all" : 100, "none" : 35 ]) );
	set ("wimpy", 5);
	set_skill("dodge", 100);
	set ("moving", 1);
    set ("weight", 100);
    set ("time_to_heal", 40);
    set ("exp_reward", 15000);
    set ("tactic_func", "cast_mela");
    set ("chat_chance",5);
    set ("chat_output", ({
      "金属史莱姆跳到你的脚旁，好奇的看著你，还对你微笑呢。\n"
    }) );
    set_c_verbs( ({ "%s撞到%s身上", "%s扑到%s脸上" }) );
    set_c_limbs( ({ "身体"  }) );
    set( "c_death_msg", "%s说: 为什麽要打我 .... 然後就死了。\n" );
    equip_armor( MOYADA"obj/slime_amulet" );
}

void cast_mela()
{
    object victim;
    if( !(victim=query_attacker()) || random(10)> 1 ) return 0;
    tell_object( victim,
      "金属史莱姆跳到你面前，吐出一颗小火球。\n" );
    tell_room( environment(this_object()), 
      "金属史莱姆跳到"+victim->query("c_name")+"面前，吐出一颗小火球。\n"
     , ({ victim, this_object() })
    );
    victim->receive_special_damage("fire", 5, 1 );
}

int catch_huntee( object who )
{
    tell_room( this_object(), 
      "金属史莱姆看见 "+who->query("c_name")+" 之後，惊吓地跳了开!\n"
   ,  ({ this_object(), who }) );
    tell_object( who, 
      "金属史莱姆看见你之後，惊吓地跳了开!\n" );
    return 1;
}
