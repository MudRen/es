#include "saulin_monk.c"

void create ()
{
        ::create();
        set_level(6);
        set_name( "basic bonze", "初级武僧" );
        add ("id", ({ "bonze","monk" }) );
        set_short("初级武僧");
        set("unit","位");
        set_long(@C_LONG
他是一位年轻的和尚，平日除了打坐念经之外，他还喜欢练武\功\
，整日见他在演武场习武，是一个标准的武痴。
C_LONG
        );
        set("alignment",100);
        set("wealth/silver",10);
        set_perm_stat("str", 9);
        set_perm_stat("dex", 9);
        set_natural_weapon(7, 6, 10);
        set_natural_armor(30, 14);
        set("max_hp", 200);
        set("hit_points", 200);
        set("max_fp", 120);
        set("force_points", 120);
	set("force_effect",2);
        set("special_defense", ([ "all" : 5, ]) );
        set("aim_difficulty", ([ "critical" : 15, "vascular" : 30, ]) );
        set("attack_skill",FIST"ro_han");
        set("gonfus/ro_han",20);
        set("gender", "male");
        set("race", "human");
        set("tactic_func","group_attack");
        set("pursuing",1);
//	set("moving",1);
//	set("speed",35);
        set("chat_chance",10);
        set("chat_output",({
          "初级武僧说道：来到少林寺请不要闹事，不要心存歹念，\n"+
          "              不然施主就别怪小僧不客气了。\n"
        }) );
        set ("att_chat_output",({
          "初级武僧喝道：你太不识相了，叫你不要闹事还不听，\n"+
          "              一定要给你一些教训!!\n"
        }) );
}

int check_partner(object obj)
{
   if( obj->query_attacker() ) return 0;
   if( (string)obj->query("name") == "basic bonze" ||
       (string)obj->query("name") == "bonze" ) return 1;
   return 0;
}

int group_attack()
{
    object victim, *guard;
    int i;
    
    victim = query_attacker();
    if(!victim) return 0;
    guard = filter_array( all_inventory(environment(this_object())),
            "check_partner", this_object() );
    for( i=0; i<sizeof(guard); i++) {
      tell_room( environment(this_object()), 
        "初级武僧大喊：大胆狂徒，竟敢在少林寺的地盘撒野！师兄弟们上呀！\n"
      );
      guard[i]->kill_ob(victim);
    }
}     
