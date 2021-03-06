#include "/d/eastland/beggar/dony.h"

inherit MONSTER;
void create()
{
        ::create();
        set_level(17);
        set_name( "master Wu","吴大海" );
        add ( "id", ({ "master","wu"}) );
        set_short("四大长老之 吴大海" );
        set("unit","位");
        set_long(@C_LONG
吴大海生得孔武有力,高大的身材,一双粗壮的臂膀看起来就让人畏惧三分。 吴
大海现今位居四大长老其中的一位,平时好喝酒为人豪爽是个直性子的人。他天
生又爱打抱不平,急公好义,同时也是帮主震八方最亲密的好友。 吴大海现在正
在跟帮主讨论一些机密事情。
C_LONG
        );
        set("weight",920);
        set("alignment",100);
        set("gender","male");
        set("race","lizardman");
        set("hit_points",700);
        set("max_hp",700);
        set_perm_stat("str",25);
        set_perm_stat("dex",23);
        set_natural_weapon(10, 5, 10);
        set_natural_armor(81,39);
        set( "special_defense", ([ "all": 40, "none": 45 ]) );
        set_skill("parry",60);
        set_skill("block",60);
        set_skill( "axe", 90 );
        equip_armor(DARMOR"silver_tail");
        equip_armor(DARMOR"dragon_shield");
        wield_weapon( DWEAPON"silver_axe" );
        set( "inquiry", ([
                    "war":"@@ask_war",
                   "talk":"@@ask_talk",       
                 "secret":"@@ask_secret"
            ]) );
        set("tactic_func","my_attack");
}
void ask_talk()
{
write(@C_LONG
吴大海说道:去去去,小孩子不要问大人的事情。
C_LONG
     );
}
void ask_war()
{
write(@C_LONG
吴大海面有难色似乎不太想说。
C_LONG
     );
}
void ask_secret()
{
    if ( !this_player()->query_temp("jail_asked") )
       tell_object(this_player(),"吴大海说道:去去去,小孩子不要随便乱问。\n");
    else {
       this_player()->set_temp("wu_asked",1);
       tell_object(this_player(),"吴大海说道:嗯,最好带帮主的手谕去。\n");
    }    
}
void die()
{
   object killer;
   string str,name;
   if ( killer=query("last_attacker") )
     name=killer->query("name");
   str="\n  "+ctime(time())+" 吴大海 killed at "+
      file_name(environment(this_player()))+" by "+name+"\n";
   write_file("/open/dony/deathlist",str);
   ::die();
}