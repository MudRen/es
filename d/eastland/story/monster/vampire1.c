#include "../story.h"
#include <stats.h>
#include <conditions.h>
#include "../magic.c"
inherit MONSTER;
int delay=6;
int duration=10;
int damage=8;
void create()
{
    ::create();
    set_level(19);
    set_name( "The great vampire", "妖□ 谷辰" );
    add ("id", ({ "vampire" }) );
    set_short( "万年妖□ 谷辰");
    set_long(@LONG
妖□谷辰长的高逾九尺，双手过膝，一身白骨也似的身体除了末梢之外，业已生长
出些许皮肉；一对翡翠眼睛，在黑暗中闪灼不已，电射出青绿色的光芒看将要聂摄
你的魂魄；那脚，好似钉了板子不会弯曲似的，一踪足，却似浑身生翼，竟有七尺
高飞出三丈远。妖□谷辰现在正摇头晃脑瞪著你瞧，两根骷髅手作势往前扑，张著
那血盆大口獠牙暴现，大有欲得你而甘心！
LONG
            );
    set("unit","位");
    set("age",100);
    set("killer",1);
    set("pursuing",1);
    set("alignment",-2500);
    set("weight",1000);
    set_perm_stat("str",30);
    set_perm_stat("dex",30);
    set_perm_stat("kar",30);
    set_perm_stat("int",30);
    set("hit_points",5000);
    set("max_hp",5000);
    set("max_fp",600);
    set_natural_armor(100,35);
    set_natural_weapon(80,40,60);
    set_skill("dodge",100);
    set_skill("unarmed",100);
    set("special_defense", ([ "all": 80,"none":30]) );
    set("aim_difficulty",
    (["critical":50,"vascular":50,"ganglion":50]) );
    set("stun_difficulty",100);
    set_c_verbs( ({
        "%s张开它的血盆大口，一口向%s咬去",
        "%s挥动它的利爪，向%s抓去"}) );
    set_c_limbs( ({ "头部", "身躯", "脚部", "双手" }) );
    equip_armor(SARM"vampire_amulet");
    set( "tactic_func", "my_tactic" );
}        
int my_tactic()
{
     object *victim,env;
     int i,max;     
     
     if (!victim=query_attackers()) return 0;
     env=environment(this_object());
     if (!query("be_hurt") && env->query("trap_set")) {
     set("be_hurt",1);
     tell_room(env,@LONG

只见地上升华出一道万丈光芒直透天上而去，忽然，



妖□ 谷辰　一道悚栗的尖叫声！！
原来地上的符咒业已发生作用，令妖□ 谷辰遭受到重创！！



LONG     
     );
     set_perm_stat("str",25);
     set_perm_stat("dex",20);
     set_perm_stat("kar",20);
     set_perm_stat("int",20);
     set("hit_points",1000);
     set_natural_armor(70,25);
     set_natural_weapon(70,30,50);
     delay=4;
     duration=5;
     damage=5;
     }
     max=sizeof(victim);
     switch( random(40) ) {    
     case 0..1 :
        tell_room(env,set_color(
           "\n\n妖□ 谷辰  吐出一口绿色的秽气充斥著整个房间！\n\n","HIG"));          
        for (i=0;i<max;i++)
          (CONDITION_PREFIX + "simple_poison")->apply_effect(victim[i],duration,damage);
        break;
     case 2..4 :
        tell_room(env,set_color(
           "妖□ 谷辰 突如其来的利爪，把敌人狠狠抓牢！\n","HIW"));
        for (i=0;i<max;i++){
           victim[i]->block_attack(delay);
           victim[i]->set_temp("msg_stop_attack",
             "(  你被妖□ 谷辰抓住因而动弹不得！  )\n");
        }
        break;
     case 5..6 :
        tell_room(env,set_color(
           "\n妖□ 谷辰 张著獠牙往敌人的颈子咬去，吸的满口都是鲜血！\n\n\n","HIR"));
        for (i=0;i<max;i++) 
           (CONDITION_PREFIX + "bleeding")->apply_effect(victim[i],duration,damage );
        break;
     default:
        break;                                  
     }
     return 0;          
}
void die()
{
    object ball,killer;
    string name;
    SAREA"vhole1"->set("have_vampire",0);
    SAREA"vhole2"->set("have_vampire",0);
    SAREA"vhole3"->set("have_vampire",0);
    SAREA"vhole1"->set("trap_set",0);
    SAREA"vhole2"->set("trap_set",0);
    SAREA"vhole3"->set("trap_set",0);
    tell_room(environment(),"谷辰临死前从肚子里掉出一个黑色的珠子。\n");
    killer=query("last_attacker");
    if ( killer ) {
       if (!(name=killer->query("org_name"))) 
          name=killer->query("name");
    } else name="????";
    ball=new(SITEM"ball1");
    ball->set("master",name);
    ball->move(environment());
    ::die();
}                  