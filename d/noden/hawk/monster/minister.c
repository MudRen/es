#include "../hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Hell Minister", "ڤ���޵�ʿ" );
        set("id",({"minister","hell minister","hell"}));
        set_short( "ڤ���޵�ʿ" );
        set_long(@LONG
ڤ���޵�ʿ��Ϊά��ڤ��ĺ�ƽ���ڵ����н��ܺڵ�˹��ѵ���ķ�
ʦ���ڵ����Ͽ���ѵ��֮�£����ǲ�����ͨ���������൱��ķ�����ͬ
ʱ������Զ�ȷ�ʦǿ׳�����壬���е���ڤȨ�ȣ�����ڤ�����ͣ���Ϊ
�޵�ʿ�ǵ�����
LONG
        );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "int", 25 );
        set_skill( "dodge" , 100 );
        set_skill( "parry" , 100 );
        set_skill( "unarmed" , 50 );
        set ("max_hp", 700 );
        set ("hit_points", 700 );
        set_natural_weapon( 35 , 15 , 30 );
        set_natural_armor( 40 , 30 );
        set( "aim_difficulty",
        ([ "critical":30,"weakest":70,"ganglion":10 ]) );
        set ("special_defense",
        ([ "monk": 20, "scholar": 20, "evil": 100 , "divine": -20,
                "fire": 80, "electric":60, "cold":60, "energy": 30]) );
        set( "race", "human" );
        set( "gender", "male" );
        set( "pursuing", 1);
        set( "killer", 1);
	wield_weapon(WEAPON"wand");
        equip_armor(ARMOR"cloth03.c");
        equip_armor(ARMOR"god_4.c");
        set( "tactic_func","my_tactic");

}

int my_tactic()
{
        int dam;
        object victim;
        if (!victim = query_attacker()) return 0;
        if ( random(25) < 21) return 0;

        tell_object(victim,@C_LONG

�޵�ʿ������������һЦ���������е�Ȩ�ȣ��૵����˼�������

ͻȻ��е��ڵ�˹������Ŀ����㣬˫��һ�ӣ�һ�����������Χס��
�����а��а�����Ʒ��ƣ�������ȵĸо������ܵ���ǰ��δ�е��˺�

C_LONG
);
        tell_room(environment(victim),@LONG

�޵�ʿ�󺰣�����ߵ�ڤ�ۣ��ҵ�����....Э���Ҵ���ҵĵ��˰ɣ�

ֻ���Ͽ�ͻȻ������һ��Ƭ���ƣ��ڵ�˹���������ĵĴ�����˷����˹�����
˭�������ҵ�ʹ��Ϊ��....���������� Quit ��Ȼ....�����ڵ�

��е�һ���ޱ�ǿ�ҵ�ɱ����Ű������ս���ϣ��޵�ʿ�ĵ����ܵ��˳�������
���˺���

LONG
);
        dam = 5 + random(5);
        victim->receive_special_damage( "evil", dam);
        victim->receive_special_damage( "divine", dam);
        victim->receive_special_damage( "fire", dam);
        victim->receive_special_damage( "cold", dam);
        victim->receive_special_damage( "electric", dam);
        victim->receive_special_damage( "energy", dam);
        victim->receive_special_damage( "acid", dam);
        victim->receive_damage(dam);
        return 1;
}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/minister",1);
        ::die();
        return;
}
