#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2;

	::create();
	set_level(19);
	set_name( "Moorth Warlock", "默尔斯战巫" );
	add( "id", ({ "warlock" }) );
	set_short( "默尔斯战巫" );
	set_long(
		"你看到一个默尔斯的「战巫」，他们是属於拉曼西斯女皇的亲卫队，不但\n"
		"施法能力不下於魔法师，高超的剑术更是令人不寒而栗！\。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -1500 );
   set( "hit_points", 550 );
   set( "max_hp", 550 );
	set( "special_defense", ([ "all": 70,"none":20 ]) );
   set( "aim_difficulty", ([ "weakest" : 40, "vascular" : 40 ]) );
   set( "natural_armor_class", 50 );
	set( "natural_defense_bonus", 30 );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 10 );
	set( "natural_max_damage1", 10 );
   set( "natural_min_damage2", 10 );
   set( "natural_max_damage2", 15 );
	set( "wealth/gold", 400 );
	set( "wimpy", 150 );
	set( "killer", 1 );
	set( "tactic_func", "my_tactic" );
// set( "war_value", 250 );
   set( "war_value", 500 );
	set_perm_stat( "str", 26 );
	set_perm_stat( "dex", 26 );
	set_perm_stat( "int", 26 );
	set_skill( "shortblade", 100 );
	set_skill( "wand", 100 );
   set_skill( "two-weapon", 100 );
	set_skill( "dodge", 100 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"默尔斯战巫大叫: 你们这些愚蠢无知的诺顿人，通通给我下地狱去吧！\n",
		"默尔斯战巫说道: 杀死你们这些垃圾简直就是浪费我的时间！\n",
		"默尔斯战巫说道: 诺顿王在哪里？叫他把赛那雷斯之冠交出来！\n"
	}) );

	ob1 = new( "/d/moorth/obj/wand" );
	ob1->move( this_object() );
	wield_weapon(ob1);
   wield_weapon2( "/d/moorth/obj/electrum_sword" );

	ob2 = new( "/d/moorth/obj/robe" );
	ob2->move( this_object() );
	equip_armor(ob2);
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim= query_attackers()) ) return 0;
	if( random(20)<4 ) {
	  for( i=0; i<sizeof(victim); i++ ) {
		message( "tell_object",
			"默尔斯战巫口中念道: Del-Ka'ta Mu-ju'ra .....\n"
			"突然，一道刺骨的寒风夹著无数冰锥吹了过来，你闻到一股血腥的气味！\n",
			victim[i],
			this_object() );
	  }
		victim->receive_special_damage("magic", 70);
		return 1;
	} else return 0;
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("knight") || who->id("soldier") || who->id("officer") ||
	who->id("magician") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"默尔斯战巫挺身保护"+who->query("c_name")+"。\n",
		this_object() );
}
