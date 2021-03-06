#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/saulin.c";

void create()
{
	object ob1;
	::create();
	set_level(16);
	set_name( "blessing monk", "药王殿 祈福僧" );
	add( "id", ({ "blesser","monk","blessing" }) );
	set_short( "药王殿 祈福僧" );
	set_long(@C_LONG
你看到一个脸色和善的僧人，他不像一般武僧那麽好斗，他的任务是
协助他的同门作战。
C_LONG
	);
	set("unit", "名" );
	set("race", "human" );
	set("gender", "male" );
	set("alignment", 200 );
	set("special_defense", ([ "all": 30, "none" : 10, ]) );
	set("aim_difficulty", ([ "critical" : 30, "vascular" : 30, ]) );
	set_natural_armor( 70, 30 );
	set_natural_weapon( 8, 10, 20 );
	set("max_hp", 550);
	set("hit_points", 550);
	set("max_fp", 1400);
	set("force_points", 1400);
	set("wealth/gold", 20 );
	set("wimpy", 30 );
	set("killer",1);
	set("tactic_func", "my_tactic");
	set_perm_stat("str", 15);
	set_perm_stat("dex", 25);
	set_perm_stat("int", 28);
	set_perm_stat("kar", 24);
	set_perm_stat("pie", 28);
	set_skill( "dagger", 50 );
	set_skill( "dodge", 80 );
	set_skill( "anatomlogy", 100 );
	set_temp( "aiming_loc", "ganglion" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
		"祈福僧说道: 你们还是放弃吧，你们撑不住的的 !\n",
		"祈福僧说道: 你们只要乖乖束手就缚我们绝不会为难你们的!\n",
        "祈福僧合什道：阿弥陀佛! 施主行为如此不堪，莫怪小僧无礼了!!\n"
    }) );

	wield_weapon( SAULIN_OBJ"healer_dagger1" );
	equip_armor( SAULIN_OBJ"cloth3" );
	equip_armor( SAULIN_OBJ"cloak3" );
	ob1 = new( SAULIN_OBJ"red_pill" ); 
    ob1->move(this_object());
}

int my_tactic()
{
	object *people;
	
	if( random(20) > 5 ) return 0;
	tell_room( environment(this_object()), 
		"祈福僧祈求道: 药王菩萨 ! 请保护少林寺的使徒啊 ! .....\n"
		"\n天空洒下一团团银白色的光芒，罩在少林僧侣们的身上。\n\n"
		, this_object()
	);
	people = all_inventory( environment() );
	people->heal_saulin(35);
	return 1;
}

void help_me_saulin(object who, object victim)
{
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"祈福僧挺身....协助" + who->query("c_name") + "作战。\n"
	       , this_object()
	);
}
