#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/saulin.c";

void create()
{
	::create();
	set_level(15);
	set_name( "Bonze", "般若堂 武僧" );
	add( "id", ({ "bonze","monk" }) );
	set_short( "般若堂 武僧" );
	set_long(
		"你看到一个武僧，他正在寻找对手想要在师叔伯面前一展自己所学。\n"
	);
	set("unit", "名" );
	set("race", "human" );
	set("gender", "male" );
	set("alignment",  300 );
	set("max_hp", 695);
	set("hit_points", 695);
	set("max_fp", 2450);
	set("force_points", 2450);
	set("special_defense", ([ "all" : 35, "none" : 21 ]) );
    set("aim_difficulty", ([ "critical" : 45, "vascular" : 35 ]) );
  	set_natural_weapon( 20, 10, 20 );
  	set_natural_armor( 78, 30 );
	set("wealth/gold", 18 );
	set("aggressive", 1 );
	set("killer", 1 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 18 );
	set_skill( "longblade", 80 );
	set_skill( "parry", 60 );
	set_skill( "dodge", 60 );
	set_skill( "defend", 60 );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
		"武僧大叫: 快快让佛爷慈悲了你们吧!!\n",
		"武僧说道: 束手就缚我就让你们少受些罪!\n",
		"武僧说道: 想在我师叔伯手下讨的好去？你趁早别作清秋大梦吧!\n"
	}) );

	wield_weapon( SAULIN_OBJ"blade4" );
	equip_armor( SAULIN_OBJ"necklace" );
}

void help_me_saulin(object who, object victim)
{
	object *tmp;

	if( who->id("monk") ) return;
	tmp = who->query_temp("protectors");
	if( !tmp || member_array(this_object(), tmp)==-1 ) {
		who->add_temp("protectors", ({this_object()}) );
		add_temp( "protectees", ({who}) );
	}
	if( !attackers || member_array(victim, attackers)==-1 )
		kill_ob(victim);
	tell_room( environment(), 
		"武僧挺身保护" + who->query("c_name") + "。\n"
		, this_object()
	);
}
