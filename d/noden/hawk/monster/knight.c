#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        seteuid(getuid());
        set_level(19);
        set_name( "Dead Spirit Knight","������ʿ" );
        add( "id",({ "knight" }) );
        set_short( "������ʿ" );
        set_long(@LONG
�����������ӵ����������������飬����������ʿ��ȥ��ȴֻ��
�������ɵ�һƬ��ʲ�ᶼ���������ֻ�о���һ�ɴӵ�������ɱ��
���������˹���
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
// ����ԭʼ�趨���Ϊ100, ��Ҫ�ټ���Ҫ����װ��!
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

"\n������ʿ�߸߾�����ƣ����س���"+
(string)victim->query("c_name")+"��ȥ��\n",victim
        );
        tell_object(victim,@C_LONG

������ʿ�߾ٶ��ƣ���������Ĵ����������㲻���������ͷ��Ѫ����
��ǰһƬ������ð
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
