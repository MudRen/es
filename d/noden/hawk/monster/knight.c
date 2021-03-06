#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        seteuid(getuid());
        set_level(19);
        set_name( "Dead Spirit Knight","死灵骑士" );
        add( "id",({ "knight" }) );
        set_short( "死灵骑士" );
        set_long(@LONG
这是裘拉根从地狱呼唤出来的亡灵，你往死灵骑士望去，却只看
到黑蒙蒙的一片，什麽都看不清楚，只感觉到一股从地狱来的杀气
正朝你扑了过来
LONG
                );
        set( "exp_reward",30000 );
        set( "gender","male" );
        set( "race","undead" );
        set( "alignment",-2500 );
        set( "killer", 1 );
        set( "pursuing", 1 );
        set_natural_armor( 35,29 );
        set_natural_weapon( 40,20,30 );
        set( "max_hp",1200 );
        set( "hit_points",1200 );
        set_perm_stat( "str",20 );
        set_perm_stat( "kar",30 );
        set_perm_stat( "dex",20 );
        set_skill( "parry",80 );
//      set_skill( "defend", 120 );
// 技巧原始设定最高为100, 若要再加则要利用装备!
        set_skill( "defend", 100 );
        set_skill( "block",80 );
        set_skill( "unarmed",80 );
        set_skill( "dodge",100 );
        set_skill( "tactic",100 );
        set( "tactic","assault" );
        set( "tactic_func","my_tactic");
        set( "special_defense",([ "all":30,"evil":80 ]) );
        set( "aim_difficulty",
        ([ "vascular":45,"ganglion":100,"weakest":35,"critical":30 ]) );
        set( "stun_difficulty",50 );
        wield_weapon( WEAPON"sword.c" );
        equip_armor(ARMOR"shield.c");
        equip_armor(ARMOR"plate.c");
        equip_armor(ARMOR"god_5.c");
}

int my_tactic()
{
        object victim;
        command("defend las");
        if(random(20)>3) return 0;
        victim = query_attacker();
        if( !victim ) return 0;
        tell_room(environment(victim),

"\n死灵骑士高高举起盾牌，疯狂地朝著"+
(string)victim->query("c_name")+"打去。\n",victim
        );
        tell_object(victim,@C_LONG

死灵骑士高举盾牌，朝著你疯狂的打来，你闪躲不及，被打得头破血流，
眼前一片金星乱冒
C_LONG
    );
        victim->receive_damage(random(10)+20);
        victim->receive_special_damage("magic",30);
        return 1;

}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/knight",1);
        ::die();
        return;
}
