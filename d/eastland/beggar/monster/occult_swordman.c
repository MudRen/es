#include "../dony.h"

#define NAME(x)     (string)x->query("c_name") 

inherit MONSTER;

void create()
{
    ::create();
    set_level(17);
    set_name( "occult swordman Fan", "���ѩ" );
    add( "id",({"swordman","fan","man"}) );
    set_short( "�������� ���ѩ");
    set_long(@LONG
������ǰ����һλ���ƺ��ص��������͡���ȫ�����²���ǧ�ٸ��˿�,�˿ڴ�����
���������������Ѫ,��Ѫ�������½�Ūʪ��, ���ı��ϻ�������һ����Լ����
�Ĵ���,һ����֪���ղźͱ��˺ݺݵĶ�һ�������ѩԭ����ȥѰ���, ���γ�
��̫������,�����ʽ����ʩչ��һ��ͱ�����,��������ش�,ֻ���˵���������
���Եȴ��ʵ��Ļ��ᡣ
LONG
            );
    set("unit","λ");
    set("race","human");      
    set("class","knight");
    set("age",18);
    set("gender","male" );
    set("alignment",6500);
    set("weight",800);
    set("wealth/gold",250);
    set_perm_stat("str",25);
    set_perm_stat("dex",22);
    set_perm_stat("kar",21);
    set_perm_stat("int",28);
    set("hit_points",580);
    set("max_hp",580);
    set_natural_armor(29,17);
    set_natural_weapon(36,15,30);
    set_skill("shortblade",80);
    set_skill("dodge",90);
    set_skill("parry",85);
    set("special_defense", ([ "all": 40,"none":30]) );
    set("aim_difficulty",
    (["critical":35,"vascular":90,"ganglion":75,"weakest":45]) );
    set("stun_difficulty",80);
    wield_weapon(DWEAPON"seven_sword");
    equip_armor(DARMOR"fun_cloak");
    equip_armor(DARMOR"fun_turban");
    equip_armor(DARMOR"fun_gloves");
    equip_armor(DARMOR"fun_boots");
    equip_armor(DARMOR"fun_belt");
    set( "chat_chance", 10 );
    set( "att_chat_output", ({
           "���ѩŭ��:����ר���۸����˵�����?\n",
           "���ѩ��Ц��:������,����Ϊ����������۸�����?\n",
           "���ѩ��:��,����ͬ��춾���!!!!\n"
    }) );
    set( "tactic_func", "my_tactic" );
    set( "inquiry", ([
         "enemy":"@@ask_enemy",
    ]) );
}        
void ask_enemy()
{
write(@C_LONG
���ѩ̾��:��,���ܰ��ұ�����?�ҵĳ�����һ���������.....
C_LONG
    );
}
int my_tactic()
{
    object env,me,victim;
    string my_name,vic_name;
        
    victim=query_attacker();
    me = this_object();
    my_name=NAME(me);
    vic_name=NAME(victim);
    env = environment(me);
                                      
    if ( !victim ) return 0;
    
    switch( random(45) ) {
    case 1..3:
       victim->receive_special_damage("evil",30);
       tell_object(victim,"\n"+
         my_name+"�����ȵ�:��һ��������ն��!!!\n\n");                                          
       report(this_object(),victim);
       tell_room(env,"\n"+
         my_name+"��"+vic_name+"��ȵ�:��һ��������ն��\n\n",victim);
       return 1;
    case 4..5:
       victim->receive_special_damage("sleet",30);
       tell_room(env,
         my_name+"�����еĽ����һ�Ű׹�,�����ư׹����.....\n\n");
       report(this_object(),victim);
       return 1;
    case 6:
       victim->receive_special_damage("divine",30);
       tell_room(env,  
         my_name+"��ɫ��Ȼ,ʹ����һ�С����ͬٱ��....\n\n");
       report(this_object(),victim);
       return 1; 
    default :
         return 0;
    }
}
