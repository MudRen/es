#include "../dony.h"

inherit DMONSTER"limit";

void create()
{
    ::create();
    set("lvlimit",15);
    set_level(7);
    set_name( "countryman ahtu", "阿土仔" );
    add( "id",({"ahtu","countryman"}) );
    set_short( "庄稼汉 阿土仔");
    set_long(@C_LONG
阿土仔穿著一件薄薄的短袖汗衫,露出两条黑拗拗的粗壮手臂, 手臂上不下几千百
个疮疤。从阿土仔衣服的破洞所露出来的身体, 你依稀可以看到一条条的括痕,这
都是阿土仔平时辛勤工作的结果。 他昨天被发现受伤( hurt )倒在路旁因而被人
抬到药铺来接受小雪子的悉心治疗。 
C_LONG
            );
    set("unit","位");
    set("gender","man" );
    set("race","human");      
    set("age",45);
    set_perm_stat( "dex", 14 );
    set_perm_stat( "str", 16 );
    set_perm_stat( "int", 7 );
    set_perm_stat( "con", 13 );
    set_perm_stat( "piety", 5 );
    set_perm_stat( "karma", 10 );
    set ("max_hp", 250);
    set ("hit_points", 250);
    set ("wealth", ([ "silver": 60 ]) );
    set_natural_weapon( 19, 10, 18 );
    set_natural_armor( 15, 2 );
    set ("weight", 550);
    set ("exp_reward", 1150 );
    set("chat_chance",2);
    set("chat_output",({
            "阿土仔不著地呻吟道:唉哟,好痛哟～\n",
            "阿土仔不著地呻吟道:早知道就不要多喝两杯。\n"
    }) );
    set("inquiry", ([
             "hurt":"@@ask_hurt"
    ]) );
}        
void ask_hurt(object asker)
{
    tell_object(asker,
     "阿土仔叹道:唉,昨天我去『牵猪哥』回来时多喝了两杯,黑漆漆的不知道\n"
     "           碰到了什麽东西,然後被压倒在地上。当我爬起来的时候,又\n"
     "           不知道被谁从後面重重的砍了一刀, 我就昏倒了。起来时就\n"
     "           在这里了, 我一向没有和人结仇,怎麽会那麽『虽』? 唉哟,\n"
     "           好痛哟～\n"
       );
}
