#include "../moyada.h"

inherit MONSTER;

int done;

void create ()
{
	object sword;
	
	::create();
	set_level(18);
	set_name( "Wan Fu", "王虎" );
	add ("id", ({ "boss", "wanfu", "wan fu", "wan", "fu" }) );
	set_short( "店长王虎" );
	set_long(@LONG
王虎是这家商店的老板，他看起来十分强壮，全身肌肉一块一块地，相当
吓人。他留著一条长长的辫子，裸著上身「亲切」的招呼著客人。噢！他还随
身携带著一把大刀，刀上刻著一条气宇轩昂的龙。
LONG
	);

    set( "alignment", 1500);
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "个" );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 5);
	set_perm_stat( "karma", 20);
	set( "aim_difficulty", ([ "critical" : 50, "weakest" : 30, ]) );
	set( "special_defense",
	   ([ "all" : 20, "none" : 10 ]) );
	set ("max_hp", 1000);
	set ("hit_points", 1000);
	set ("wealth", ([ "gold": 100 ]) );
	set_natural_weapon( 40, 20, 30 );
	set_natural_armor( 85, 45 );
    set ("weight", 900);
    set( "exp_reward", 20000 );
    set( "inquiry", ([
         "job" : "@@ask_job",
         "devil" : "听说恶魔常常伪装成平常人, 需要特殊的物品才能让他现形。\n",
    ]) );
    
	set ("chat_chance", 5);
	set ("chat_output", ({
	    "王虎用毛巾擦完桌子後便开心地擦拭他的大刀。\n",
	    }) ); 
	set ("att_chat_output", ({
	    "王虎说：小子，你胆敢向我挑战，有胆！\n",
	    "王虎说：你还不和解吗? 你不可能打败我的。\n",
	    "王虎说：再给你一次机会，你还不投降吗? \n",
	    }) );
	wield_weapon(MOYADA"obj/glaive");
	set("tactic_func", "special_attack");
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()), 
      "王虎很不爽的向"+who->query("c_name")+"说: 你还敢进来，活的不耐烦了，我就成全你，死吧!\n"
    ,  ({ this_object(), who }) );
    tell_object( who,
      "王虎很不爽的向你说: 你还敢进来，活的不耐烦了，我就成全你，死吧!\n"
    );
    return 1;
}

void ask_job( object who )
{
      if( done )
        tell_object( who,
          "王虎说：对不起，我们现在不缺人。\n");
      else 
        tell_object( who, 
          "王虎说：我的储物室据说躲著一只恶魔，客人都不敢上门，你能帮我除掉它吗?\n");
}

int member_killer( string a, string *b )
{
    int i;
    if( !b ) return 0;
    for( i=0; i<sizeof(b); i++ )
      if( a == b[i] ) return 1;
    return 0;
}

int hunt_check( object wanfu, object victim )
{
    int i;
    object *attackers;
    string *hunt_list;
    
    hunt_list = wanfu->query("hunt_list");
    attackers = wanfu->query_attackers();
    if( victim && !member_group( victim, attackers ) &&
        member_killer( (string)victim->query("name"), hunt_list ) ) {
      tell_room( environment(wanfu), 
        "王虎大笑著说: "+victim->query("c_name")+"，你以为 quit 就能逃出我的手掌心吗? 死吧!\n"
        , wanfu );
      kill_ob( victim );
      return 1;
    }
    return 0;
}

void relay_message(string class1, string msg)
{
	string who, str;
	object player;

	if( sscanf( msg, "%s(%s)走了过来。", str,who )==2 ) {
		if( !player = find_player(lower_case(who)) ) return;
		if( hunt_check( this_object(), player ) ) return;
		if( !done && ((int)player->query_quest_level("wanfu")) < 1 &&
			player->query_temp("wanfu/done") ) {
			tell_object( player, @THANKS
王虎说：谢谢你，这是你该得的报酬。
王虎给你 50 枚金币，你获得 12000 点经验。
   [   你完成了王虎的任务。   ] 
THANKS
);

			player->gain_experience(12000);
			player->credit("gold", 50);
			player->finish_quest("wanfu", 1);
			done = 1;
			return;
		}
		tell_room( environment(), 
			"王虎说：欢迎光临，需要什麽吗？\n" );
	} else if( sscanf( msg, "%s往%s边离开。", who,str )==2 )
		tell_room( environment(), 
			"王虎说：谢谢光临，下次再来。\n" );
}

int special_attack()
{// 15% use it! damage 45-55.
    object *victim;
    string *hunt_list, victim_name;
    int i;
    
    if( !query_attacker() ) return 0;
    hunt_list = (string *)this_object()->query("hunt_list");
    victim_name = (string)query_attacker()->query("name");
    if( !hunt_list )
      hunt_list = ({ victim_name });
    else if( !member_killer( victim_name, hunt_list ) )
      hunt_list += ({ victim_name });
    this_object()->set("hunt_list", hunt_list);
    
    if( !(victim = query_attackers()) || (random(20)<3) ) return 0;
    tell_room( environment( this_object() ), 
      "王虎大喊: 看我的绝招 爆炎斩! \n"
      "  只见王虎往上一跳，他的大刀伴随著火焰向所有敌人砸下。\n"
      "一阵爆炸之後，王虎跑过来把大刀捡了回去。\n" ,
      this_object()
    );
    i = sizeof(victim);
    while(i--) {
      victim[i]->receive_damage(45+random(10));
      "/d/magic/magic"->report( this_object(), victim[i] );
    }
    return 1;
}

void reset()
{
    done = 0;
}
