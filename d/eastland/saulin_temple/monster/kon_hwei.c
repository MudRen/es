#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/mob_special";

void create()
{
        ::create();
        set_level(16);
        set_name( "kon hwei", "文殊院长老 空慧" );
        add ("id", ({ "hwei","monk","kon" }) );
        set_short( "文殊院长老 空慧");
        set("unit","位");
        set_long(@DESC
他是一位老年和尚，两道白眉长长的垂下来，带著亲切的笑容，虽然
他的武功\修为比不上他的同辈长老们，但是他对经学禅理上的见解，
却连方丈大师都十分崇敬，推为少林经师第一，所以他掌理文殊院实
是众望所归。
DESC
        );
        set("alignment",800);
        set("wealth/silver",500);
        set_perm_stat("str", 25);
        set_perm_stat("dex", 25);
        set_perm_stat("int", 29);
        set("max_hp", 600);
        set("hit_points", 600);
        set("max_fp", 500);
        set("force_points", 500);
	set("force_effect",2);
        set_natural_weapon(30, 22, 34);
        set_natural_armor(65, 20);
        set("special_defense", ([ "all" : 30, "none" : 20 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50, ]) );
        set_skill("parry",100);
        set_skill("unarmed",100);
        set ("gender", "male");
        set ("race", "human");
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/body-def",10);
	equip_armor(SAULIN_OBJ"cloth3");
	equip_armor(SAULIN_OBJ"necklace2");
        set("special_attack",(["damage_type" : "mental","main_damage" : 20,
				"random_dam" : 40 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg","空慧大师喃喃的唱出波罗密心经..\n"+
    "\n突然，你的心灵深处的邪恶力量受到强烈的震汤 ..\n\n");
set("c_room_msg","空慧大师唱出波罗密心经，驱赶");
set("c_room_msg2", "心灵深处的邪恶 ...\n");
}

