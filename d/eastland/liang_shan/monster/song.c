#include "../takeda.h" 

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(16);
	set_name( "Song Jiang", "宋江" );
	set_short( "宋江" );
	set_long(
@C_LONG
    表字公明，外号呼保义，人称及时雨宋公明，郓城县宋家村人。幼攻经史，
长有权谋，驰名大孝，仗义疏财，为梁山泊总兵部头领，名闻遐迩，震动京师。
C_LONG
	);
	set( "unit", "名" );
	add ("id", ({"song","jiang" }) );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 27 );
	set_perm_stat( "kar", 28 );
	set_skill( "dodge", 100 );
	set_skill( "unarmed_parry",100 );
	set_skill( "unarmed", 100 );
	set( "time_to_heal",2 );
	set( "special_defense", ([ "all": 50 ]) );
	set("aim_difficulty", ([ "critical":30, "vascular":55, "ganglion":50 ]) );
	set("stun_difficulty/ma",40 );
	set( "gender", "male" );
	set( "race", "human" );
	set_temp("detect_invi", 1);
	set_temp("effect/detect-invis", 1);
	
	set_temp("detect_hide", 1);
        set_temp("effect/detect-hide", 1);
	set( "alignment", 2400 );
	set_natural_armor( 70, 30 );
	set_natural_weapon( 45, 25, 38 );
	set( "defense_type","berserk");
	set( "wealth/gold", 160 );
	set_c_verbs( ({ "%s神态悠闲自然, 静静的看著%s",
		"%s负手而立, 对著%s发出会心微笑", "%s轻轻摇头, 伸手拍拍%s",
		"%s一声清啸, %s感觉一阵酸麻"
		 }) );

	set( "tactic_func", "my_tactic" );
        equip_armor( TARMOR"phoenix_helmet");
        equip_armor( TARMOR"waterlily_boots");
        equip_armor( TARMOR"gold_chainmail");
        equip_armor( TARMOR"hoshi_jade");

}

int my_tactic()
{
	object victim,bandit;
        string stat;
        int n;

	if( random(5)>1 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	if( victim->query_temp("caught") < 3 ) {
	victim->add_temp("caught",1) ;
	tell_object( victim, 
"\n宋江叹道: 看汝此等武艺, 亦属不凡, 吾上体天心, 今乃网开一面! \n"
"放汝一条生路便是.......\n\n"
"宋江挥挥手, 一群喽罗把你带到大寨门, 然後一把将你推倒在地\n");
	tell_room( environment(), 
"\n宋江派出一堆喽罗把" + victim->query("c_name") + "，抬到别处放生\n",
		 this_object()  );

 victim->receive_damage(5);
 victim->move_player( TROOM"gate1","*** 你看到"+victim->query("c_name")+"像一只狗般被人丢出来 ***","");

 tell_object( victim, 
 "\n你被摔了个狗吃屎，一些鲜血从你的嘴角中流了出来，四周的人似乎都在笑你 \n\n");
	return 1;
}
        tell_object( victim,
        "\n宋江骂道: 泥人亦有三分火气, 你道我无法整治你吗? \n\n"
        "宋江挥挥手, 一群喽罗把你抓去地牢, 然後一把将你推倒在地\n");
        tell_room( environment(),
        "\n宋江挥挥手，一堆喽罗把" + victim->query("c_name") + "，拎到地牢动用私刑...\n",
                 this_object()  );
        victim->receive_damage(30);
        bandit = new(TMONSTER"small_bandit");
        
 victim->move_player( TROOM"jail1","*** 你看到"+victim->query("c_name")+"像一只狗般被人丢出来 ***","");
 bandit->move(environment(victim));
 bandit->kill_ob(victim);
 tell_object( victim,
  "\n你被摔了个狗吃屎，一些鲜血从你的嘴角中流了出来，四周的人似乎都在笑你 \n\n");
 return 1;  

}