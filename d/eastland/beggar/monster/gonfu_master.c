#include "../dony.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(16);
        set_name( "gonfu master","项长老" );
        add ( "id", ({ "master","gonfu"}) );
        set_short("项长老" );
        set("unit","位");
        set_long(@C_LONG
项长老位居丐帮的传功长老,平时掌管两项镇帮神功『降龙十八掌』和『打狗棒法
』。项长老三十多年前为了逃避仇人的追杀而稳居到『薪胆村』来,日子一久忘了
自己叫什麽,只记得姓项而己, 所以大家都称呼他为『项长老』。前些时候丐帮内
乱,项长老因平靖有功,被升为二大长老之一。别看他老态龙钟的样子,他可也是很
厉害的哟。 
C_LONG
        );
        set("alignment",1200);
        set("wealth/silver",700);
        set("gender","male");
        set("race","human");
        set("hit_points",450);
        set("force_points",400);
        set("max_hp",450);
        set("weight",710);
        set_perm_stat("str",22);
        set_perm_stat("dex",18);
        set_perm_stat("int",10);
        set_perm_stat("kar",15);
        set_natural_weapon(30, 12, 25);
        set_natural_armor(20,20);
        set( "special_defense", ([ "all": 20, "none": 20 ]) );
        set( "aim_difficulty",([ "weakest":100,"vascular":30,"ganglion":20 ]) );
        set( "stun_difficulty",50 );
        set_skill("dodge",55);
        set_skill("parry",65);
        wield_weapon(DWEAPON"blunt");
        equip_armor(DARMOR"broken_cloth");
        set( "inquiry", ([
                  "chan":"@@ask_chan",
                  "war":"@@ask_war"
        ]) );
        set("tactic_func","my_attack");
}
void ask_chan( object asker )
{
     if ( asker->query_temp("unary_asked") ) {
        tell_object( asker,
           "项长老说道:喔, 你要打听全副帮主的消息? 最近他没有和我联络, 所以我也不知\n"
           "           道他到底在什麽地方。对了,他最喜欢喝酒了,你可以去有酒的地方找\n"
           "           找看。 如果你找到他之後顺便帮我劝劝他,说他老子是自作孽不可活\n"
           "           ,叫他千万不可步他老子的後尘,他老子也就是十多年前的叛变(war)\n"
           "           弟子--全执祥,不然像他这麽一个大好英雄的前程会白白给毁了。\n"
        );
        asker->set_temp("gonfu_asked",1);
        return ;
     } 
        tell_object( asker,
           "项长老摇摇头说道:我不知道。\n");
}
void ask_war( object asker )
{
write(@C_LONG        
项长老叹道:唉,十多年前,本帮中有一位颇为聪明的弟子,由於他千方百计想得到帮主之位
           ,不惜以外面的力量,打击本帮,顿时帮内遭到一场空前的活劫;那时,死伤无数
           ,□骨堆积成山鲜血流成河,帮内精英消失殆尽,所幸在 帮主 震八方英明的领
           导之下,击溃敌人无数,才能挽救现在的局面。但为了安抚不安的叛变的弟子,
           不得已委以那位弟子的遗孤重任,所幸,那遗孤也英雄了得,替帮内整顿得好生
           兴旺。那遗弧也就是现在的全副帮主,那时的叛变弟子自是他父亲--全执祥。
           最近,全副帮主不知道从那里打听到全执祥的消息,唉,如果没有人好好替他开
           导,以他热血情操,真不知....唉,希望不要再有十多年前的惨事发生。
C_LONG
     );
}            

int my_attack()
{
    object victim,wea1,wea2;
    
    if( !(victim = query_attacker()) ) return 0;

    if( random(30) < 2 ) { 
      tell_room( environment(this_object()),
          "项长老使出了『打狗棒法』之『□』字诀把"+
          victim->query("c_name")+"□倒了!!\n",victim);
      tell_object( victim,
          "项长老使出了『打狗棒法』之『□』字诀把你给□倒了!!\n");         
      victim->receive_damage(15);
      victim->block_attack(8);
      victim->set_temp("msg_stop_attack",
          "(  你被□倒了,瞬间无法攻击 !!  )\n");
      return 1;                     
    } else if ( random(30) < 4 ) {
        tell_room( environment(this_object()),
           "项长老使出了『打狗棒法』之『黏』字诀......\n");
           victim->receive_damage(10);
           wea1=victim->query("weapon1");
           wea2=victim->query("weapon2");
           if (wea1) wea1->unwield(1);
           if (wea2) wea2->unwield(1);
           return 1;
    } return 0;
}

