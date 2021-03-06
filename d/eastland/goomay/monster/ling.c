#include "../goomay.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "Ling", "灵儿" );
	add ("id", ({  "girl" }) );
	set_short( "灵儿" );
	set_long(
"灵儿年约二十一，一身劲装，看似温婉，实则聪明干练。她正对你盈盈而笑 \n" 
"灵儿是玉女剑派弟子中的佼佼者。玉女剑派向来只收女弟子，而她们最痛恨 \n" 
"贪色不正当之徒，所以其师祖罗萝特创『屠狼剑法』，专门用来砍杀色狼。 \n"
"灵儿自幼练习此剑法，已得其真传，专杀天下好色之徒。 \n"
	);
	set( "alignment",1000);
	set( "gender", "female" );
	set( "race", "imp" );
	set( "unit", "位" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "piety", 25);
	set_skill("longblade",80);
	set_skill("dodge",80);
        set_skill("parry",100);
	set("defense_type","defense");
	set("special_defense", ([ "all":35, "none":25 ]) );
	set("aim_difficulty", ([ "critical":20, "vascular":27, ]) );
	set("max_hp", 500);
	set("max_fp", 1000);
	set("hit_points", 500);
	set("force_effect", 1);
	set("force_points", 1000);
	set("attack_skill","monster/sword1");
	set("wealth/gold", 100);
	set_natural_weapon(21,10,13);
	set_natural_armor( 69, 18 );
	wield_weapon( Obj"rainbow_sword" );
	equip_armor( Obj"gold_necklace" );
	equip_armor( Obj"green_cloth" );
}
