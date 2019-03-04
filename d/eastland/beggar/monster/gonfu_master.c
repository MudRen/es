#include "../dony.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(16);
        set_name( "gonfu master","���" );
        add ( "id", ({ "master","gonfu"}) );
        set_short("���" );
        set("unit","λ");
        set_long(@C_LONG
���λ��ؤ��Ĵ�������,ƽʱ�ƹ���������񹦡�����ʮ���ơ��͡��򹷰���
���������ʮ����ǰΪ���ӱܳ��˵�׷ɱ���Ⱦӵ���н���塻��,����һ������
�Լ���ʲ��,ֻ�ǵ��������, ���Դ�Ҷ��ƺ���Ϊ����ϡ���ǰЩʱ��ؤ����
��,�����ƽ���й�,����Ϊ������֮һ��������̬���ӵ�����,����Ҳ�Ǻ�
������Ӵ�� 
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
           "���˵��:�, ��Ҫ����ȫ����������Ϣ? �����û�к�������, ������Ҳ��֪\n"
           "           ����������ʲ��ط�������,����ϲ���Ⱦ���,�����ȥ�оƵĵط���\n"
           "           �ҿ��� ������ҵ���֮��˳�����ȰȰ��,˵�����������������ɻ�\n"
           "           ,����ǧ�򲻿ɲ������ӵ��᳾,������Ҳ����ʮ����ǰ���ѱ�(war)\n"
           "           ����--ȫִ��,��Ȼ��������һ�����Ӣ�۵�ǰ�̻�װ׸����ˡ�\n"
        );
        asker->set_temp("gonfu_asked",1);
        return ;
     } 
        tell_object( asker,
           "���ҡҡͷ˵��:�Ҳ�֪����\n");
}
void ask_war( object asker )
{
write(@C_LONG        
���̾��:��,ʮ����ǰ,��������һλ��Ϊ�����ĵ���,�����ǧ���ټ���õ�����֮λ
           ,��ϧ�����������,�������,��ʱ�����⵽һ����ǰ�Ļ��;��ʱ,��������
           ,���Ƕѻ���ɽ��Ѫ���ɺ�,���ھ�Ӣ��ʧ����,������ ���� ��˷�Ӣ������
           ��֮��,������������,����������ڵľ��档��Ϊ�˰����������ѱ�ĵ���,
           ������ί����λ���ӵ��Ź�����,����,���Ź�ҲӢ���˵�,��������ٵú���
           ���������Ż�Ҳ�������ڵ�ȫ������,��ʱ���ѱ��������������--ȫִ�顣
           ���,ȫ��������֪�������������ȫִ�����Ϣ,��,���û���˺ú�������
           ��,������Ѫ���,�治֪....��,ϣ����Ҫ����ʮ����ǰ�Ĳ��·�����
C_LONG
     );
}            

int my_attack()
{
    object victim,wea1,wea2;
    
    if( !(victim = query_attacker()) ) return 0;

    if( random(30) < 2 ) { 
      tell_room( environment(this_object()),
          "���ʹ���ˡ��򹷰�����֮�������־���"+
          victim->query("c_name")+"������!!\n",victim);
      tell_object( victim,
          "���ʹ���ˡ��򹷰�����֮�������־������������!!\n");         
      victim->receive_damage(15);
      victim->block_attack(8);
      victim->set_temp("msg_stop_attack",
          "(  �㱻������,˲���޷����� !!  )\n");
      return 1;                     
    } else if ( random(30) < 4 ) {
        tell_room( environment(this_object()),
           "���ʹ���ˡ��򹷰�����֮��𤡻�־�......\n");
           victim->receive_damage(10);
           wea1=victim->query("weapon1");
           wea2=victim->query("weapon2");
           if (wea1) wea1->unwield(1);
           if (wea2) wea2->unwield(1);
           return 1;
    } return 0;
}

