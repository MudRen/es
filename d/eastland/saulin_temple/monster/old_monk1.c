
#include "../saulin_temple.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(19);
        set_name( "old monk", "������ɮ" );
        add ("id", ({ "monk" }) );
        set_short("������ɮ");
        set("unit","λ");
        set_long(@C_LONG
�����������½�����λ���ֱ��ĳ���֮һ��Ҳ��ǰ���εķ��ɡ�����
���ʱ��ϲ��ϰ�䣬�����͵ľ�����\���׽������Ȼ�������֡�����
�������Ѿ����������ˣ�����ż�������������ش��ʵ�ʱ�������Σ
���⣬ƽʱ����������ɽ�������ꡣ
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
"\n�������������\��һ�����������Ե���ӿ��˫�֣���"+
(string)victim->query("c_name")+"ֱ���ȥ��\n",victim);
    tell_object(victim,@C_LONG
    
�������������\����ʱ�㱻һ��ǿ���������������ͻȻ��ɾ���ֱ��
��ĵ���������ľ����ƺ��Ѿ����ˡ�

C_LONG
                   );
    victim->receive_damage(60-random(fp/10));
   return 1;
}
