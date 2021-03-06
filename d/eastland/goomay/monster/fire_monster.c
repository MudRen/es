#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
        set_name( "fire monster", "火焰兽" );
        add( "id", ({ "monster" }) );
        set_short( "火焰兽" );
        set_long( @C_LONG
你看到一只浑身发出红色火焰的妖怪，它的双眼散发出一种妖异的光芒
，即使是身经百战的你，面对著这样一只根本不可能存在於世上的妖物
，也忍不住心中直冒寒意。
C_LONG
);
	set("killer",1);
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
	set("defense_type","dodge");
	set( "alignment", -1500 );
	set( "natural_armor_class", 70 );
	set( "natural_defense_bonus", 30 );
	set( "natural_weapon_class1", 30 );
	set( "natural_min_damage1", 12 );
	set( "natural_max_damage1", 23 );
	set( "tactic_func", "my_tactic" );
}

void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
     sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
   return;
}

int my_tactic()
{
	object *victim,ob;
	int i,spec;

	spec=random(100);
	if (spec <20 && (victim = query_attackers()))
	{
	tell_room( environment(this_object()), 
		"\n火焰兽喷出一蓬火焰，烧灼你的身体 !!\n\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
	    {
		victim[i]->receive_special_damage( "fire", 20+random(10) );
		report(this_object(),victim[i]);
	    }
		return 1;
	}
	else if ( spec>20 && spec<50 && (victim = query_attackers()) ) 
	{
        tell_room( environment(this_object()), 
		"\n火焰兽散发出强烈的光芒，你的眼睛一阵刺痛 !!\n\n" ,
                this_object() );
        for( i=0; i<sizeof(victim); i++ )
	{
        ob = present("glasses", victim[i]);
        if(ob && ob->query("equipped"))
			tell_object( victim[i], "你的墨镜挡住了刺眼的强光。\n\n");
		else
		{
	        if( victim[i]->query("stop_attack") ) continue;
	        victim[i]->block_attack(8);
	        victim[i]->set_temp("msg_stop_attack", 
	          "( 你现在什麽也看不到 ! )\n" );
		}
	}
	return 1;
	}
	return 0;
}

void die()
{
		tell_room( environment(this_object()), 
			"火焰兽大叫：「黑暗之母 !! 救我 !!」 ....\n\n"
			"一道黑色的烟雾突然笼罩住火焰兽，然後消失的无影无踪\n"
			"你听到一个声音从你的背後中发出: 「你以为打败了无能的火焰兽，事情就会这样就结束吗？哈哈哈 !!」\n\n"
			"你回头一看，一个女人正站在你的背後。她手上捧著一尊女神像\n"
			"「受死吧 !!」她大叫一声，变身成为一只人头蛇身的妖怪\n\n" ,
			this_object() );
		set( "alt_corpse", Mob"snake" );
		::die(1);
}
