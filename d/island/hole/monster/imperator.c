#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "Lizardman Imperial Akaba","阿卡巴" );
	add( "id",({ "lizardman","imperator","akaba" }) );
	set_short( "蜥蜴人大将军 阿卡巴" );
	set_long(@LONG
你所看到的是一位身经百战的大将军。据说，当它还在军队中的时候
，因生性残暴，每次出任务时总是以杀人为乐，而且愈杀愈兴奋，所
以又有个外号--魔鬼将军。已经不知道有少英雄好汉丧生在它的双斧
之下了。
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",-500000 );
//	set( "time_to_heal",8 );
	set_natural_armor( 55,20 );
	set_natural_weapon( 30,20,22 );
	set_natural_weapon2( 30,20,24 );
	set( "max_hp",1000 );
	set( "hit_points",1000 );
	set( "spell_points",10000 );
	set_perm_stat( "str",30 );
	set_perm_stat( "kar",25 );
	set_perm_stat( "dex",30 );
	set_skill( "parry",100 );
	set_skill( "axe",100 );
	set_skill( "two-weapon",100 );
	set_skill( "dodge",100 );
	set_skill( "tactic",100 );
	set( "wealth/gold",150 );
	set( "special_defense",([ "fire":50,"cold":50,"energy":50,"magic":50,"none":40 ]) );
	set( "aim_difficulty",
	([ "vascular":80,"critical":70,"weakest":50,"ganglion":80 ])  );
	set( "stun_difficulty",60 );
	set( "tactic","assault" );
	wield_weapon( HWEAPON"axe1" );
	equip_armor( HARMOR"cloak2" );
	equip_armor( HARMOR"ring3" );
	equip_armor( HARMOR"plate9" );
	equip_armor( HARMOR"helmet5" );
}

void init()
{
	::init();
	add_action( "to_embattle","embattle" );
	add_action( "to_demand","demand" );
}

int to_embattle()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"阿卡巴狠狠的瞪了"+c_him+"一眼说道：车轮战？想都别想，单挑吧。\n",player );
	tell_object( player,"阿卡巴狠狠的瞪了你一眼说道：车轮战？想都别想，单挑吧。\n" );
	command( "kill "+him );
	return 1;
}

int to_demand()
{
	object player,env;
	string him,c_him;
	
	player=this_player();
	env=environment(player);
	him=player->query( "name" );
	c_him=player->query( "c_name" );
	tell_room( env,
	"阿卡巴狠狠的瞪了"+c_him+"一眼说道：找帮手？想都别想，乖乖单挑吧。\n",player );
	tell_object( player,"阿卡巴狠狠的瞪了你一眼说道：找帮手？想都别想，乖乖单挑吧。\n" );
	command( "kill "+him );
	return 1;
}

void die()
{
	this_object()->set( "alignment",-1000 );
	::die();
}
