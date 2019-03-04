#include "../dony.h"

inherit MONSTER;
int times;

void create()
{
	::create();
	set_level(19);
	set_name( "unknow prisoner","��֪��" );
	add ("id", ({"prisoner"}) );
	set_short( "���� ��֪��" );
	set_long(@C_LONG
����ǰ������һ����Լ�ˡ���ʮ�������;����������ȫ�������ۻ಻��,�����·�
����ɢ����һ�������ڱǵ���Ϣ; ���㾪ѽ�����������ִֵľ�����������������
�ùǴ��˹�ȥ,���˸�����ǽ����;����֮��,ȫ�����²���ǧ�ٸ��̺�,����˵�ǵ�
�˲���˵���ܵ������ҵĿ��̡���˵,�����Ǻ䶯һʱ�Ĵ�ħͷ,���ܵ��˴����ɵ�
Χ�������Ʒ������Ų����Ϊ�����֡�
C_LONG
	);
	set( "unit", "��" );
	set_perm_stat( "str", 28 );
	set_perm_stat( "dex", 26 );
	set_perm_stat( "int", 24 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 22 );
        set("weight",900);
	set_skill( "dodge", 90 );
	set_skill( "unarmed", 90 );
        set_skill( "unarmed-parry",100);    
	set( "special_defense", ([ "all": 60,"none":60]) );
	set("aim_difficulty", 
	   ([ "critical":80, "vascular":60, "ganglion":70, "weakest":70 ]) );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -4000 );
	set("max_hp", 650);
	set("hit_points",650);
	set("force_points",350);
	set_natural_armor( 55,50 );
	set_natural_weapon( 90,30,55);
	set( "wealth/gold", 400 );
        set_temp("detect_hide",1);
        set_temp("detect_invi",1);
        equip_armor(DARMOR"fighter_ring.c");
	set( "tactic_func", "my_tactic" );
        set_c_verbs( ({ "%s�ڿ�Ծ��ͷһ�������ƶ���%s����",
                        "%s����ǰ̤һ��ʮָ��צ��%sһץ,�����Ѽ�",
                        "%sʹ����������ʮ��ʽ��������%s�ݺ�һɨ"
                    }) );
}

int my_tactic()
{
     int i,ran;
     object *env,victim;
     string vic_name;
     
     if (!victim= query_attacker()) 
        return 0;
     vic_name=victim->query("c_name");
     if( times ) {
        if (times==6)
           tell_room(environment(this_object()),
             "\n��֪����ʼʩչ���Ǵ�......\n\n");
        if( --times ) {
           tell_object( victim,"��������ȡ��������\n");
           tell_room(environment(this_object()),
               vic_name+"����ȡȫ��ľ�����\n",victim);
           victim->receive_damage(10);
           victim->block_attack(2);
           victim->set_temp("msg_stop_attack","(  ��������ȡ��������������!!  )\n");
           if ( ( victim->query("class") )=="monk" )
               victim->add( "force_points", -10 );
           report(this_object(),victim);
           return 1;
        } else {
           this_object()->set_natural_armor( 55,50 );
           tell_room(environment(this_object()),"\n��֪������¶������ı���:�ñ��ñ�,��������������\n");
           return 1;
        }
     }       
     ran=random(40);
     if ( ran>34 ) {
         times = 6;
         this_object()->set_natural_armor( 40,40 );
         return 0;
     } 
     else if ( ran>30 ) {
        tell_object(victim,
           "\n��֪����������ʹ���ˡ���ˮ֮�衹,����ͷ���ۻ�����\n\n");
        tell_room(environment(this_object()),
           "��֪����������ʹ���ˡ���ˮ֮�衹��"+vic_name+"���������ظ������裡��\n",victim);
        (CONDITION_PREFIX + "confused")->apply_effect( victim, 10, 8 );         
        return 0;
     } 
}

void die()
{
   object eq;
   tell_room(environment(this_object()),
      "\n\n��Ȼ,��֪���ġ������˱䶯.....��������Ȼ��������û��!!\n\n\n");
   eq=present("ring",this_object());
   eq->unequip(1);
   eq->move(environment(this_object()));
   set( "alt_corpse", DMONSTER"ch_prisoner.c" );
   ::die(1);
}        