#include <mudlib.h>
#include <daemons.h>
inherit WEAPON;

void create()
{
    set_name("Rainbow ruler","七彩璇天尺");
    add("id", ({ "ruler" }) );
    set_short("七彩璇天尺");
    set_long(@C_LONG
一把美玉制成不满三尺长的尺，尺身雕工精致，镶有玉石珠宝，不时发出璇烂虹光
，名贵无比。
C_LONG
    );
    set( "unit", "把" );
    setup_weapon("thrusting", 45,30,45);
    set( "weight",200);
    set( "value", ({ 8000, "silver" }) );
    set("hit_func","special_attect");
    set_c_verbs( ({ 
        "手执%s用力甩打%s",
        "的%s斗然变成三丈长，直直戳向%s",
        "凌空而起双手合执%s，当著%s狠狠劈下",
        "手中的%s突然变长，一记横扫千军之势攻向%s"
    }) );
    set("extra_stats",(["dex":-5]));
}

int special_attect(object victim,int damage)
{
   object holder;
   string hname,vname;
   int my_str,vic_kar,dam,degree,hour;

   if( !victim ) return 0;

   if( !(holder = environment(this_object())) || !living(holder) ) return 0;
   
   if( holder->query("spell_points")< 4) return 0;
   my_str=holder->query_stat("str");
   vic_kar=victim->query_stat("kar");
   vic_kar=vic_kar<5?5:vic_kar;
   degree=3*my_str-2*vic_kar+10;
   if( random(degree)<vic_kar ) return 0;
   hname=holder->query("c_name");
   vname=victim->query("c_name");
   victim->set("last_attacker", holder );
   if ( !holder->query("npc") )
      holder->add("spell_points",-4);
   sscanf(WEATHER_D->query_game_time(),"%d",hour);
   if ( ( hour > 18 ) || ( hour < 6 ) ) {
      dam=40;
      tell_object(holder,sprintf(
         "你手中的璇天尺随著夜晚的来临，把%s笼罩在一片七色璇丽光芒里！\n\n\n",
         vname));
      tell_object(victim,sprintf(
         "\n%s手中的璇天尺随著夜晚的来临，把你笼罩在一片七色璇丽光芒里！\n\n",
         hname));
      tell_room(environment(holder),sprintf(                        
         "%s手中的璇天尺随著夜晚的来临，%s笼罩在一片七色璇丽光芒里！\n",
         hname,vname),({holder,victim}));     
      victim->receive_special_damage( "mental",dam );
   }
   else {
      dam=30;
      tell_object(holder,sprintf(
         "你手中的璇天尺发出一道圣洁的光芒，驱散了%s内心的邪恶感！\n\n\n",
         vname));
      tell_object(victim,sprintf(
         "\n%s手中的璇天尺发出一道圣洁的光芒，驱散了你内心的邪恶感！\n\n",
         hname));
      tell_room(environment(holder),sprintf(
         "%s手中的璇天尺发出一道圣洁的光芒，射入了%s的心脏！\n",
         hname,vname),({holder,victim})); 
         victim->add("alignment",50);
         victim->receive_special_damage( "divine",dam );
   }
   return dam+damage;
}
