#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Poet Las", "吟游诗人 拉斯" );
        add ("id", ({ "las", "poet" }) );
        set_short( "吟游诗人 拉斯");
        set_long(@LONG
拉斯是魔族中罕见的吟游诗人，天性好杀，却不喜和人结伴，正巧
与裘拉根结识为好友，为了要寻找高强的敌手，他就风尘仆仆的赶到死
亡竞技场，为那些不自量力的冒险者开起地狱之门。他看起来脸色惨白
无光，青筋暴露，一副弱不禁风的样子，不过你可千万不要以为他这样
就是好欺负的。
LONG
        );
        set_perm_stat("str", 30 );
        set_perm_stat("con", 25 );
        set_perm_stat("int", 30 );
        set_perm_stat("dex",15);
        set_skill( "dodge", 100 );
        set_skill( "blunt", 85 );
        set( "alignment", -1500 );
        set( "race", "daemon" );
        set( "gender", "male" );
        set( "hit_points", 900 );
        set( "max_hp", 900 );
        set( "killer", 1);
        set( "pursuing", 1);
        set( "tactic_func","my_tactic");
        set( "aim_difficulty",
        ([ "critical":80,"weakest":20,"ganglion":30,"vascular":50 ]) );
        set_natural_weapon( 20, 20, 30 );
        set_natural_armor( 25, 40 );
        set ("special_defense", ([
                "monk": 20, "scholar": 20, "all": 20 , "none" : 20]) );
        command("party form");
	wield_weapon(WEAPON"flute");
        equip_armor(ARMOR"shield1.c");
        equip_armor(ARMOR"god_2.c");
        equip_armor(ARMOR"white_suit.c");
}

int stop_attack(object player)
{
        call_out( "defend_las", 1, player);
        return 0;
}

void defend_las(object obj)
{
        int i;
        object env, *inv, atk;

        env = environment( this_object() );
        if( !env ) return;

        inv = all_inventory(env);
        atk = query_attacker();
        for( i=0; i<sizeof(inv); i++ ) {
                if( (string)inv[i]->query("name")=="Dead Spirit Knight" &&
inv[i]!=atk){
        //      && (!atk || member_array( inv[i], atk )==-1) ) {
                        tell_room( env,
                                inv[i]->query("c_name") +
"冲到拉斯面前，全力保护著拉斯！\n",
                                inv[i] );
                        inv[i]->force_me( "protect king" );
                        inv[i]->kill_ob(atk);
                }
        }
        return;
}

int my_tactic()
{
        int choice;
        object victim;

        if (!victim = query_attacker()) return 0;
        switch(choice=random(3) )
       {
        case 0 : return 0;
                 break;
        case 1 :
//地狱交响曲
        if ( random(20) < 16) return 0;
        tell_room(environment(victim),
"\n拉斯缓缓的将长笛拿到嘴边，对著"+
(string)victim->query("c_name")+"吹奏出气势澎湃的地狱交响曲，一时
雷电交加，天地变色，彷佛地狱之门已为"+(string)victim->query("c_name")+"打开。\n"
,victim
        );
        tell_object(victim,@C_LONG

拉斯将长笛拿到嘴边，似笑非笑，吹奏起凄绝的地狱交响曲！
～～～嗡～～呜～～呜呜～～～～～嗡～～～～
音乐一起，霎时间天地变色，空气凝结了！黑暗斗气随著笛声将你团团围住！

你感觉到身上的皮肉开始脱离你的躯壳，而你只能不由自主的随著笛音起舞，
脑中开始回忆起从小到大的所有美好回忆，你看见远方有著飞翔在空中的精灵
在跟你招手，在更远的前方似乎还有个拿著镰刀的家伙在冷笑著.......

C_LONG
    );
        victim->receive_special_damage( "evil", random(10)+30);
        return 1;
      break;
    case 2:
//死亡诗篇
        if ( random(20) < 17 ) return 0;
        tell_room(environment(victim),
"\n拉斯转过身子，面对著"+
(string)victim->query("c_name")+"悠悠的念出一段长而优美的诗篇，只见"+
(string)victim->query("c_name")+"脸上露出笑容，身子不住的摇晃著！！\n"
        );
        tell_object(victim,@C_LONG

拉斯转过身来面对著你，看著手中的诗集，对你喃喃吟颂著：
        若有那自称高贵超凡，
                必被那善良纯洁所耻；
        若有那自命恶贯满盈，
        　　　　必受那邪灵奸佞所困。
        无知的欲求有灵的无限，
        　　在殒落的刹那，重生之门也为之开启啊！

你边听著拉斯所吟唱的诗篇....一边心有所感....不由得心中一阵
绞痛....惭愧不已....
C_LONG
    );
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack",
                "( 你心中充满悔意，无法攻击！ )\n" );
        victim->receive_special_damage( "devine", random(25)+40);
        return 1;
        break;
        default: return 0;
        break;
     }

}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/las",1);
        ::die();
        return;
}
