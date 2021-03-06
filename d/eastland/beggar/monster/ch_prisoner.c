#include "../dony.h"

inherit MONSTER;
int times;
void create()
{
	::create();
	set_level(19);
	set_name( "unknow prisoner","不知名[发狂中]" );
	add ("id", ({"prisoner"}) );
	set_short(set_color("囚犯 不知名[发狂中]","HIR"));
	set_long(@C_LONG
你眼前所见是一个年约八、九十岁的老人;他长发披肩全身上下污秽不堪,他的衣服
处处散发著一股令人掩鼻的气息; 让你惊呀的是有两条粗粗的精铁铸锁□从他的琵
琶骨穿了过去,两端各连在墙壁上;除此之外,全身上下不下千百个疤痕,与其说是刀
伤不如说是受到极悲惨的酷刑。据说,他曾是轰动一时的大魔头,但受到八大门派的
围□并且制服了他才不致於为害武林。
C_LONG
	);
	set( "unit", "名" );
        set("killer",1);
	set_perm_stat( "str", 28 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 29 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 25 );
        set("weight",900);
	set_skill( "dodge", 100 );
	set_skill( "unarmed", 100 );
        set_skill( "unarmed-parry",100);    
	set( "special_defense", ([ "all": 70,"none":70]) );
	set("aim_difficulty", 
	   ([ "critical":120, "vascular":40, "ganglion":70, "weakest":70 ]) );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -5000 );
	set("max_hp", 1800);
	set("hit_points",1800);
	set("force_points",500);
	set_natural_armor( 90,30 );
	set_natural_weapon( 110,35,63);
	set( "wealth/gold", 400 );
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        equip_armor(DARMOR"fighter_ring1.c");
	set( "tactic_func", "my_tactic" );
        set_c_verbs( ({ "%s腾空跃起当头一记劈空掌对著%s劈下",
                        "%s脚往前踏一步十指成爪往%s一抓,凌厉已极",
                        "%s使出六、六三十六式旋风腿往%s狠狠一扫"
                    }) );
        set( "chat_chance", 2 );
        set( "att_chat_output", ({
             "不知名嘲笑你的无知:连我你也敢招惹,真是活得不耐烦了！！ \n",
             "你发现对手实在是太强了,一道道冷汗从你的背脊流下!! \n"
        }) );
        
}

int my_tactic()
{
     int i,ran;
     object *env,victim;
     string vic_name,mob_name;
     
     if (!victim= query_attacker()) 
         return 0;
     vic_name=victim->query("c_name");
     mob_name=this_object()->query("c_name");
     if( times ) {
        if (times==11)
           tell_room(environment(this_object()),
             "\n"+mob_name+"开始施展吸星大法......\n\n");
        if( --times ) {
           tell_object( victim,"你正被吸取精力！！\n");
           tell_room(environment(this_object()),
               vic_name+"被吸取全身的精力！\n",victim);
           victim->receive_damage(10);
           victim->block_attack(2);
           victim->set_temp("msg_stop_attack","(  你正被吸取精力而动弹不得!!  )\n");
           this_object()->receive_healing(5);
           if ( ( victim->query("class") )=="monk" )
               victim->add( "force_points", -10 );
           report(this_object(),victim);
           return 1;
        } else {
           this_object()->set_natural_armor( 90,30 );
           tell_room(environment(this_object()),
             "\n"+mob_name+"脸上露出满意的表情:好饱好饱,哈哈哈哈哈！！\n");
           return 1;
        }
     }       
     ran=random(80);
     if ( ran>77 ) {
         times = 11;
         this_object()->set_natural_armor( 80,20 );
         return 0;
     } 
     else if ( ran>74 ) {
        tell_object(victim,
           "\n"+mob_name+"盘旋而起使出了「天水之舞」,令你头昏眼花！！\n\n");
        tell_room(environment(this_object()),
           mob_name+"盘旋而起使出了「天水之舞」令"+vic_name+"不由自主地跟著起舞！！\n",victim);
        (CONDITION_PREFIX + "confused")->apply_effect( victim, 5, 5 );         
        return 0;
     } 
     else if ( ran>72 ) {
        tell_object(victim,
           "\n"+mob_name+"两手一青一赤使出了「元阴元阳掌」,往你身上一按,登时真气大□！！\n\n");
        tell_room(environment(this_object()),
           mob_name+"两手一青一赤使出了「元阴元阳掌」,往"+vic_name+"身上一按！！\n",victim);
        victim->receive_special_damage("fire",20);
        victim->receive_special_dmage("sleet",20);
        victim->add( "force_points", -20 );
        victim->add( "spell_points", -40 );
        report(this_object(),victim);
        return 0;         
     }
     else if ( ran>70 ) {
        tell_object(victim,
           "\n"+mob_name+"双手急速舞动,一招「北斗真空截风冲」切断你周遭的空气！！\n\n");
        tell_room(environment(this_object()),
           mob_name+"双手急速舞动,一阵风压让你喘不过气来！！\n",victim);
        (CONDITION_PREFIX + "slow")->apply_effect( victim, 5, 5 );
        (CONDITION_PREFIX + "weak")->apply_effect( victim, 5, 5 );
        return 0;
     }           
     else if ( ran>65 ) {
        tell_object(victim,
           "\n"+mob_name+"喝道: \n"
           "\n看我的不传之秘 :「修罗金刚指」向你的檀中穴一点！！\n\n");
        tell_room(environment(this_object()),
           "\n"+mob_name+"一股强劲的指力向"+vic_name+"弹去！！\n",victim);
        victim->receive_damage(30);
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack","(  你被点住了穴道而无法移动  )\n");
        return 0;                     
     }
}

void die()
{
   tell_room(environment(this_object()),
       "\n不知名谓然长叹道:唉,没想到我竟死於这些鼠辈手中......\n\n");
   ::die(1);
}        