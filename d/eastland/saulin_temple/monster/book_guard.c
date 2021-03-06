#include "saulin_monk.c"

void create()
{
        ::create();
        set_level(16);
        set_name( "The library Guardian", "守阁僧" );
        add ("id", ({ "bonze","monk","guardian" }) );
        set_short( "守阁僧");
        set("unit","位");
        set_long(
@DESC
他是一位中年和尚，身材魁梧气度不凡，虽然带著亲切的笑容，但是
看他手迟步涩、太阳穴高高鼓起，就知道他一定是内外兼修的高手。
DESC
        );
        set("alignment",800);
        set("wealth/silver",500);
        set_perm_stat("str", 23);
        set_perm_stat("dex", 25);
        set_natural_weapon(24, 20, 36);
        set_natural_armor(55, 30);
        set("max_hp", 500);
        set("hit_points", 500);
        set("max_fp",200);
        set("force_points", 200);
	set("force_effect",2);
        set("special_defense", ([ "all" : 40, "none" : 20 ]) );
        set("aim_difficulty", ([ "critical" : 50, "vascular" : 50, ]) );
        set_skill("parry",80);
        set_skill("unarmed",100);
        set ("gender", "male");
        set ("race", "human");
	set("attack_skill",CLASS"keep_flower");
	set("monk_gonfu/keep-flower",10);
        set ("tactic_func","group_attack");
        set ("chat_chance",7);
        set ("chat_output",({
          "守阁僧说道：藏经阁乃是本寺重地，请施主留步。\n"
        }));
        set ("att_chat_output",({
          "守阁僧喝道：施主一意孤行，请恕小僧失礼了!!\n"
        }));
	equip_armor(SAULIN_OBJ"cloth5a");
	equip_armor(SAULIN_OBJ"necklace01");
}

int check_partner(object obj)
{
   if( obj->query_attacker() ) return 0;
   if( (string)obj->query("name") == "The library keeper" ) return 1;
   return 0;
}

int group_attack()
{
    object victim,*guard;
    int i;
    victim = query_attacker();
    if (!victim) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "check_partner",this_object());
    for(i=0;i<sizeof(guard); i++){
      tell_room(environment(this_object()),
        "掌阁僧大喊：大胆狂徒，竟敢擅闯藏经阁！师兄！我来助你！\n"
      );
      guard[i]->kill_ob(victim);
    }
}     
