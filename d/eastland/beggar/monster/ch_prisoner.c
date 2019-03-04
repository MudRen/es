#include "../dony.h"

inherit MONSTER;
int times;
void create()
{
	::create();
	set_level(19);
	set_name( "unknow prisoner","��֪��[������]" );
	add ("id", ({"prisoner"}) );
	set_short(set_color("���� ��֪��[������]","HIR"));
	set_long(@C_LONG
����ǰ������һ����Լ�ˡ���ʮ�������;����������ȫ�������ۻ಻��,�����·�
����ɢ����һ�������ڱǵ���Ϣ; ���㾪ѽ�����������ִֵľ�����������������
�ùǴ��˹�ȥ,���˸�����ǽ����;����֮��,ȫ�����²���ǧ�ٸ��̺�,����˵�ǵ�
�˲���˵���ܵ������ҵĿ��̡���˵,�����Ǻ䶯һʱ�Ĵ�ħͷ,���ܵ��˴����ɵ�
Χ�������Ʒ������Ų����Ϊ�����֡�
C_LONG
	);
	set( "unit", "��" );
        set("killer",1);
	set_perm_stat( "str", 28 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 29 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 25 );
        set("weight",900);
	set_skill( "dodge", 100 );
	set_skill( "unarmed", 100 );
        set_skill( "unarmed-parry",100);    
	set( "special_defense", ([ "all": 70,"none":70]) );
	set("aim_difficulty", 
	   ([ "critical":120, "vascular":40, "ganglion":70, "weakest":70 ]) );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -5000 );
	set("max_hp", 1800);
	set("hit_points",1800);
	set("force_points",500);
	set_natural_armor( 90,30 );
	set_natural_weapon( 110,35,63);
	set( "wealth/gold", 400 );
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        equip_armor(DARMOR"fighter_ring1.c");
	set( "tactic_func", "my_tactic" );
        set_c_verbs( ({ "%s�ڿ�Ծ��ͷһ�������ƶ���%s����",
                        "%s����ǰ̤һ��ʮָ��צ��%sһץ,�����Ѽ�",
                        "%sʹ����������ʮ��ʽ��������%s�ݺ�һɨ"
                    }) );
        set( "chat_chance", 2 );
        set( "att_chat_output", ({
             "��֪����Ц�����֪:������Ҳ������,���ǻ�ò��ͷ��ˣ��� \n",
             "�㷢�ֶ���ʵ����̫ǿ��,һ�����亹����ı�������!! \n"
        }) );
        
}

int my_tactic()
{
     int i,ran;
     object *env,victim;
     string vic_name,mob_name;
     
     if (!victim= query_attacker()) 
         return 0;
     vic_name=victim->query("c_name");
     mob_name=this_object()->query("c_name");
     if( times ) {
        if (times==11)
           tell_room(environment(this_object()),
             "\n"+mob_name+"��ʼʩչ���Ǵ�......\n\n");
        if( --times ) {
           tell_object( victim,"��������ȡ��������\n");
           tell_room(environment(this_object()),
               vic_name+"����ȡȫ��ľ�����\n",victim);
           victim->receive_damage(10);
           victim->block_attack(2);
           victim->set_temp("msg_stop_attack","(  ��������ȡ��������������!!  )\n");
           this_object()->receive_healing(5);
           if ( ( victim->query("class") )=="monk" )
               victim->add( "force_points", -10 );
           report(this_object(),victim);
           return 1;
        } else {
           this_object()->set_natural_armor( 90,30 );
           tell_room(environment(this_object()),
             "\n"+mob_name+"����¶������ı���:�ñ��ñ�,��������������\n");
           return 1;
        }
     }       
     ran=random(80);
     if ( ran>77 ) {
         times = 11;
         this_object()->set_natural_armor( 80,20 );
         return 0;
     } 
     else if ( ran>74 ) {
        tell_object(victim,
           "\n"+mob_name+"��������ʹ���ˡ���ˮ֮�衹,����ͷ���ۻ�����\n\n");
        tell_room(environment(this_object()),
           mob_name+"��������ʹ���ˡ���ˮ֮�衹��"+vic_name+"���������ظ������裡��\n",victim);
        (CONDITION_PREFIX + "confused")->apply_effect( victim, 5, 5 );         
        return 0;
     } 
     else if ( ran>72 ) {
        tell_object(victim,
           "\n"+mob_name+"����һ��һ��ʹ���ˡ�Ԫ��Ԫ���ơ�,��������һ��,��ʱ�����������\n\n");
        tell_room(environment(this_object()),
           mob_name+"����һ��һ��ʹ���ˡ�Ԫ��Ԫ���ơ�,��"+vic_name+"����һ������\n",victim);
        victim->receive_special_damage("fire",20);
        victim->receive_special_dmage("sleet",20);
        victim->add( "force_points", -20 );
        victim->add( "spell_points", -40 );
        report(this_object(),victim);
        return 0;         
     }
     else if ( ran>70 ) {
        tell_object(victim,
           "\n"+mob_name+"˫�ּ����趯,һ�С�������սط�塹�ж�������Ŀ�������\n\n");
        tell_room(environment(this_object()),
           mob_name+"˫�ּ����趯,һ���ѹ���㴭������������\n",victim);
        (CONDITION_PREFIX + "slow")->apply_effect( victim, 5, 5 );
        (CONDITION_PREFIX + "weak")->apply_effect( victim, 5, 5 );
        return 0;
     }           
     else if ( ran>65 ) {
        tell_object(victim,
           "\n"+mob_name+"�ȵ�: \n"
           "\n���ҵĲ���֮�� :�����޽��ָ�������̴��Ѩһ�㣡��\n\n");
        tell_room(environment(this_object()),
           "\n"+mob_name+"һ��ǿ����ָ����"+vic_name+"��ȥ����\n",victim);
        victim->receive_damage(30);
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack","(  �㱻��ס��Ѩ�����޷��ƶ�  )\n");
        return 0;                     
     }
}

void die()
{
   tell_room(environment(this_object()),
       "\n��֪��νȻ��̾��:��,û�뵽�Ҿ������Щ������......\n\n");
   ::die(1);
}        