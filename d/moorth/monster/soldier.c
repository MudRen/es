#include <mudlib.h>

inherit "/d/moorth/monster/moorth";

void create()
{
	object ob1;

	::create();
	set_level(8);
	set_name( "Moorth Soldier", "默尔斯士兵" );
	add( "id", ({ "soldier" }) );
	set_short( "默尔斯士兵" );
	set_long(
		"你看到一个默尔斯的士兵，他正在寻找敌人——并且企图建立战功\。\n"
	);
	set( "unit", "名" );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -300 );
	set( "wealth/silver", 50 );
	set( "aggressive", 1 );
	set( "pursuing", 1 );
	set( "moving", 1 );
	set( "speed", 30 );
// set( "war_value", 5 );
   set( "war_value", 10 );
	set_perm_stat( "str", 12 );
	set_perm_stat( "dex", 10 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 30 );
	set_skill( "defend", 40 );
	set( "chat_chance", 20 );
	set( "att_chat_output", ({
		"默尔斯士兵大叫: 拉娜西斯女皇陛下万岁！\n",
		"默尔斯士兵说道: 丢下你的武器乖乖受死吧！\n",
		"默尔斯士兵说道: 你们不可能赢的，胜利是属於默尔斯帝国的！\n"
	}) );

	ob1 = new( "/d/moorth/obj/shortsword" );
	ob1->move( this_object() );
	wield_weapon(ob1);
}

void help_me_moorth(object who, object victim)
{
	object *tmp;

	if( who->id("soldier") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"默尔斯士兵挺身保护" +who->query("c_name") +"。\n",
		this_object() );
}
