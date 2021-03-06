#include "../goomay.h" 

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "wrestler wu-bu-la-kuei", "乌不拉龟" );
	set_short( "摔角手乌不拉龟" );
	set_long(@C_LONG
乌不拉龟是从塞外来的摔角好手，听说东方有许\多武功\和肉搏的比赛和武斗
他特别远从家乡赶来参加。他有一身结实的肌肉，看来非常的强壮。 
C_LONG
	);
	set( "unit", "名" );
	add ("id", ({"wu","bu","la","kuei","wrestler" }) );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 80 );
	set_skill( "unarmed", 90 );
	set( "special_defense", ([ "all": 30 ]) );
	set("aim_difficulty", ([ "critical":25, "vascular":45, "ganglion":50 ]) );
	set("stun_difficulty/ma",30 );
	set( "gender", "male" );
	set( "race", "orc" );
	set( "alignment", -400 );
	set_natural_armor( 65, 27 );
	set_natural_weapon( 32, 17, 28 );
	set( "wealth/gold", 60 );
	set_c_verbs( ({ "%s向前一进，一记猛拳打向%s", "%s左腿往%s一踢",
		"%s大吼一声，右拳劈向%s", "%s往前一纵，往%s飞扑而去",
		"%s横扑而来，双腿绞向%s", "%s如旋风转了起来，飞向%s",
		"%s压住%s的肩膀，用头撞他", "%s右拳卧紧，左拳如风，直取%s",
		"%s狂笑一阵，突然用手腕扫向%s" }) );

	set( "tactic_func", "my_tactic" );
        equip_armor( Obj"stone_armband");
        equip_armor( Obj"win_head");

}

int my_tactic()
{
	object victim;
        string stat;
        int n;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_object( victim, "\n乌不拉龟大叫一声，看我的『笨牛飞天』，把你一把抓起丢了出去! \n");

	tell_room( environment(victim),"\n乌不拉龟突然一把抓住" + victim->query("c_name") + "，将他举在头上转了起来！\n",
		({ victim, this_object() }) );

	switch( n= random(4) ) {
		case 0: stat = Goomay"mgate";	break;
		case 1: stat = Goomay"row14";	break;
		case 2: stat = Goomay"col22";	break;
		case 3: stat = Goomay"row13";	break;
		default : break;
	}

 victim->receive_damage(8);
 victim->move_player( stat,"*** 你看到"+victim->query("c_name")+"像一颗流星般飞了出去 ***","");

 tell_object( victim, 
 "\n你被摔了个狗吃屎，一些鲜血从你的嘴角中流了出来，四周的人似乎都在笑你 \n\n");

	tell_room( environment(victim), 
		  "\n" +  victim->query("c_name") + "唱著『飞呀、飞呀、小飞侠...』，从天上飞了下来，他是超人吗? 快去找他签名!!! \n\n",
		({ victim, this_object() }) );
	return 1;
}
