
#include "../saulin_temple.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "old monk", "玄慈神僧" );
        add ("id", ({ "monk" }) );
        set_short("玄慈神僧");
        set("unit","位");
        set_long(@C_LONG
玄慈是少林寺仅存数位玄字辈的长老之一，也是前两任的方丈。他年
轻的时候喜欢习武，所练就的九阳神功\和易筋经至今仍然傲视武林。但是
他现在已经不问世事了，除了偶尔少林寺遇到重大变故的时候会出面解危
以外，平时都隐居在後山安享晚年。
C_LONG
        );
        set("exp_reward",50000);
        set("alignment",2000);
        set("wealth/silver",100);
        set("gender","male");
        set("race","human");
        set("tactic_func","special_attack");
        set("hit_points",2000);
        set("force_points",2500);
        set("max_hp",2000);
        set("max_fp",2500);
        set_perm_stat("str",30);
        set_perm_stat("dex",30);
        set_perm_stat("pie",30);
        set_perm_stat("kar",30);
        set_perm_stat("con",30);
        set_perm_stat("int",30);
        set_natural_weapon(35,14,30);
        set_natural_armor(90,30);
        set_skill("dodge",100);
        set_skill("bo",100);
        set_skill("parry",100);
        set_skill("inner-force",100);
//        wield_weapon(SAULIN_OBJ"kingkong_staff");
        equip_armor(SAULIN_OBJ"necklace01");
        equip_armor(SAULIN_OBJ"cloth1a");
        equip_armor(SAULIN_OBJ"armband1");
        equip_armor(SAULIN_OBJ"ring1");
        equip_armor(SAULIN_OBJ"boot1");
}

int special_attack()
{
    object victim;
    int fp;
    victim = query_attacker();
    fp=(int)victim->query("force_points");
    if(!victim) return 0;
    if(random(20)>7) return 0;
    tell_room(environment(victim),
"\n玄慈运起九阳神功\，一道浑厚的内力自丹田涌向双手，向"+
(string)victim->query("c_name")+"直冲而去。\n",victim);
    tell_object(victim,@C_LONG
    
玄慈运起九阳神功\，霎时你被一股强大的内力笼罩著。突然这股劲力直冲
你的丹田，你觉得你的经脉似乎已经断了。

C_LONG
                   );
    victim->receive_damage(60-random(fp/10));
   return 1;
}
