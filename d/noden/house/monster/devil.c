#include <mudlib.h>

inherit MONSTER;
int is_zapped = 0;

void create()
{
	::create();
	set_level(13);
	set_name( "devil boy", "恶魔少年" );
	add( "id", ({ "boy" }) );
	set_short( "恶魔少年" );
	set_long(
		"这个小男孩有黑色的眼珠和红色的头发，他的额头上有一个恶魔的标记，当\n"
		"你的视线接触到他的眼睛时，你看到因邪恶而散发出的光彩。\n"
	);
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
	set( "killer", 1 );
   set( "race", "daemon" );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set( "natural_armor_class", 40 );
	set( "natural_defense_bonus", 200 );	// You need an incantation to change this *grin*
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 11 );
	set( "natural_max_damage1", 20 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
		"恶魔少年说道: 嘿嘿嘿 .... 你既然见到了我，就别想活命！\n",
		"恶魔少年脸上露出邪恶的笑容。\n",
		"恶魔少年歇斯底里地发出梦呓般的怪叫: 杀呀！杀呀！杀呀！\n"
	}) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<18 || !(victim = query_attackers()) ) return 0;
	tell_room( environment(this_object()), 
		"恶魔少年喃喃地念著诡异的咒文，使你觉得心脏绞痛！\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "evil", 30 );
	return 1;
}

// This function is called by the incantation of exorcise
void zapped()
{
	is_zapped = 1;
	set( "natural_defense_bonus", 20 );
	calc_armor_class();
	tell_room( environment(this_object()), 
		"恶魔少年一见到驱魔咒，大声尖叫: 该死的家伙！把那个东西拿开！\n" ,
		this_object() );
}

void die()
{
        object killer;
	killer = query("last_attacker");
	if( is_zapped ) {
		killer->set_temp("devil_killer",1);
		::die();
	}
	else {
		tell_room( environment(this_object()), 
			"恶魔少年咳出几口鲜血，倒在地上 ....\n\n"
			"你听到一阵沙哑的声音从恶魔少年的尸体发出: 「你以为这样就完了吗？休想！」\n\n"
			"恶魔少年的尸体又站了起来！\n\n" ,
			this_object() );
		set( "exp_reward", 1 );
		set( "alt_corpse", "/d/noden/house/monster/devil" );
		::die(1);
	}
}
