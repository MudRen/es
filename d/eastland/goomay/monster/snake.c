#include <../goomay.h>
#include <stats.h>
#include <conditions.h>
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
        set_name( "daemonic snake", "蛇魔女" );
        add( "id", ({ "snake" }) );
        set_short( "蛇魔女" );
        set_long( @C_LONG
你看到一只人头蛇身的妖怪，它的双眼散发出一种妖异的光芒，即使
是身经百战的你，面对著这样一只根本不可能存在於世上的妖物，也
忍不住心中直冒寒意。
C_LONG
);
	set("killer",1);
	set("gender","female");
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 26 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 18 );
	set_skill( "parry", 100 );
	set( "alignment", -1500 );
	set( "natural_armor_class", 85 );
	set( "natural_defense_bonus", 35 );
	set( "natural_weapon_class1", 50 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 );
	set( "tactic_func", "my_tactic" );
}

void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
    sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim))
   );
   return;
}

int my_tactic()
{
	object *victim,ob;
	int i,spec;

	if ( !victim = query_attackers() ) return 0 ;
        spec=random(100);
        if ( spec>50 ) return 0;

	if (spec <20)
	{
	tell_room( environment(this_object()), 
		"\n蛇魔女喷出一滩酸液，腐蚀你的身体 !!\n\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
	    {
		victim[i]->receive_special_damage( "acid", 30+random(10) );
		report(this_object(),victim[i]);
	    }
		return 1;
	}

	if ( spec<30 ) 
	{
        tell_room( environment(this_object()), 
		"\n蛇魔女喷出一团毒雾，你感到一阵晕眩 !!\n\n" ,
                this_object() );
        for( i=0; i<sizeof(victim); i++ )
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim[i], 10, 7 );
		return 1;
	}

	if ( spec<50)
	{
	tell_room( environment(this_object()), 
		"\n蛇魔女用她那对妖异的眼睛盯著你看，你的脑中突然一片空白 !!\n\n" ,
		 this_object() );
	for( i=0; i<sizeof(victim); i++ )
		(CONDITION_PREFIX + "confused")->apply_effect( victim[i], 15, 5 );
	return 1;
	}

	return 0;
}

void die()
{
	object ob1;
	ob1 = new( Obj"statue" );
	ob1->set("who_get_me",query("last_attacker")->query("name"));
        ob1->move(this_object());
                ::die(1);
	tell_room( environment(this_object()), @FLEE
一道黑色的烟雾突然笼罩住蛇魔女，你冲进黑雾中，却见女神像发出一片圣洁的
银光逐渐向黑雾中隐去，你赶紧用手抓住它，只觉得一股极强的力道从彼端传来
，然後消失的无影无踪，你不禁跌了开去，等你站起身来，黑雾已经散去了。

一阵刺耳的笑声回汤在你的耳际: 嘻嘻嘻嘻 ... 愚蠢的人啊 ...这次小让你了，
别以为黑暗的力量会就此放手 ... 我会回来的 ...

FLEE
		,this_object() );
}
