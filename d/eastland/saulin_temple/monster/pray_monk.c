#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "The Prayer", "文殊院诵经僧" );
	add( "id", ({ "prayer","monk" }) );
	set_short(  "文殊院诵经僧" );
	set_long(
		"你看到一个少林寺文殊院的诵经僧，他的口中正喃喃地念著奇特的经文！\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment",  800 );
	set( "max_hp", 500 );
	set( "max_fp", 1500 );
	set( "hit_points", 500 );
	set( "force_points", 1500 );
	set("force_effect",2);
	set( "special_defense", ([ "all": 40, "none" : 20, ]) );
	set( "aim_difficulty", ([ "critical" : 35, "vascular" : 25, ]) );
	set_natural_armor( 51, 20 );
	set_natural_weapon( -19, 11, 20 );
	set( "wealth/gold", 10 );
	seteuid( getuid() );
	set( "wimpy", 25 );
	set( "tactic_func", "my_tactic" );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "int", 28 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 23 );
	set_skill( "wand", 100 );
	set_skill( "dodge", 90 );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
		"诵经僧柔声劝道：来人赶快放下武器投降吧! 少林寺不会为难你们的!\n",
		"诵经僧柔声劝道：苦海无边! 赶快放下屠刀吧!\n"
	}) );

	wield_weapon( SAULIN_OBJ"holy_wand" );
	equip_armor( SAULIN_OBJ"ring3" ); 
	equip_armor( SAULIN_OBJ"cloth4" );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers()) ) return 0;
	if( random(20)>4 ) return 0;
	tell_room( environment(this_object()), 
		"老僧口中念道: 『苦海无边，回头是岸』.....\n"
		"\n突然，一道纯洁的圣光贯入大家的胸膛，你们感到一阵心碎的剧痛 !\n\n"
		, this_object()
	);
	for ( i=0; i < sizeof(victim) ; i++)
		victim[i]->receive_special_damage("divine", 30+random(10));
	return 1;
}
