#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1, ob2;

	::create();
	set_level(14);
	set_name( "Moorth Officer", "默尔斯军官" );
	add( "id", ({ "officer" }) );
	set_short("默尔斯军官" );
	set_long(
		"你看到一个默尔斯的军官，他正在寻找敌人——并且企图建立战功\。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -300 );
	set_natural_armor(30,25);
	set_natural_weapon(8,10,10);
    set( "special_defense", ([ "all":10 ]) );
    set( "aim_difficulty",
        ([ "critical":10, "vascular":10, "weakest":20 ]));
	
	set( "wealth/silver", 110 );
	set( "aggressive", 1 );
// set( "war_value", 20 );
   set( "war_value", 40 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 16 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 70 );
	set_skill( "block", 75 );
	set_skill( "defend", 80 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"默尔斯军官大叫: 天佑吾皇！荣耀归我默尔斯、\n",
		"默尔斯军官说道: 丢下武器，不要做无谓的抵抗！\n",
		"默尔斯军官说道: 你们这些野蛮人，快向默尔斯帝国投降！\n"
	}) );

	ob1 = new( "/d/moorth/obj/longsword" );
	ob1->move( this_object() );
	wield_weapon(ob1);

	ob2 = new( "/d/moorth/obj/shield" );
	ob2->move( this_object() );
	equip_armor(ob2);
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("soldier") || who->id("officer") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"默尔斯军官挺身保护" + who->query("c_name") + "。\n",
		this_object() );
}
