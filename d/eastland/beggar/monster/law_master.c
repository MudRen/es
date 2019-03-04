#include "../dony.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(17);
        set_name( "law master","奉令先" );
        add ( "id", ({ "master","law"}) );
        set_short("执法长老 奉令先" );
        set("unit","位");
        set_long(@C_LONG
你眼前所见的是一个面色蜡黄又颇具威仪的老丐。 奉令先一副道貌岸然的样子位
居丐帮中的要位执法长老,向来铁面无私,帮中一概大小人等,纵然并不违犯帮规刑
条,见到他也是惧怕三分。他使的是一对判官笔,在江湖上鲜有对手。
C_LONG
        );
        set("weight",720);
        set("alignment",2500);
        set("wealth/silver",800);
        set("gender","male");
        set("race","human");
        set("hit_points",540);
        set("max_hp",540);
        set_perm_stat("str",23);
        set_perm_stat("int",25);
        set_perm_stat("dex",20);
        set_natural_weapon(30, 15, 20);
        set( "natural_weapon_class2", 30 );
        set( "natural_min_damage2", 15 );
        set( "natural_max_damage2", 20 );
        set_natural_armor(65,25);
        set( "special_defense", ([ "all": 25, "none": 20 ]) );
        set( "aim_difficulty",([ "weakest":40,"vascular":40,"ganglion":40 ]) );
        set_skill("dodge",60);
        set_skill("parry",70);
        set_skill( "thrusting", 90 );
        set_skill( "two-weapon", 90 );
        wield_weapon( "/d/eastland/haiwei/obj/pen" );
        wield_weapon2( "/d/eastland/haiwei/obj/pen" );
        equip_armor(DARMOR"turban");
        set( "inquiry", ([
                   "jail":"@@ask_jail",
                    "war":"@@ask_war"
            ]) );
        set("tactic_func","my_attack");
}
void ask_jail( object asker )
{
     if ( !asker->query_temp("keeper_finish2") )
        tell_object( asker ,
           "奉令先说道:小孩子没事问什麽监狱,去去去。\n");
     else {      
        asker->set_temp("jail_asked",1);
        tell_object( asker ,
           "奉令先说道:在村中的某个角落(corner)有一条路可以通往监狱。\n"
           "           不过话说回来,你问这个干什麽,不要做坏事喔,不然\n"
           "           我会修理你的。\n"           
                ); 
     }
}
void ask_war()
{
write(@C_LONG
奉令先面有难色似乎不太想说。
C_LONG
     );
}