// ��������⹥���ο� : Mobs' special attack inherit
// Code by : Ruby of ES at 7/30/94
// ע�� : ����(inherit)����ʽ�ᣬҪ�ڳ�ʽ���ж������⹥���Ĳ���
// ��:  set("special_attack",(["damage_type" : "none","main_damage" : 10,
//                              "random_dam" : 5 , "hit_rate" : 20]));
//      set( "tactic_func", "my_tactic" );
// �����������ѶϢ��������Ӣ�ĵ� enemy_msg,room_msg,room_msg2 ��������

#include <mudlib.h>
inherit MONSTER;

// ��ʾ����������������� : write by Echobomber
void report( object attacker, object victim )
{
   string message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,"( ��"+message+" )\n");
}

// ���������ڶ���ʽ���ɱ����¶��������ӱ仯�ԡ�

// ʹ�����⹥��ʧ�ܶ��ⷴ�������� : fail_to_use()
int fail_to_use()       { return 0; }

// ���⹥���ĳ��ֻ���  : special_hit_rate()
int special_hit_rate() 
 { return (int)query("special_attack/hit_rate") ; }

// ���⹥������ɵ��˺� : special_damage()
int special_damage(object victim)
    { return (int)query("special_attack/main_damage")+
		random(query("special_attack/random_damage")) ; }

// �����˺������� : special_type() ������ 11 ��
// Ϊ : fire,code,electric,energy,mental,acid,poison,magic,evil,divine,none
string special_type() 
     { return (string)query("special_attack/damage_type") ; }

// �ڶ������⹥��Ԥ���� : �����ٶ���һ�����ϵ����⹥����̬
int second_special_attack() { return 0 ; }

int my_tactic()
{
        object victim;

if( random(100) > special_hit_rate() ||
	!(victim= query_attacker()) ) return 0;

// ��������¶��� fail_to_use() ! ���������Ҳ���趨��Ӣ�ĵ� fail_room_msg
    if ( fail_to_use() ) {
                tell_room( environment(), 
			query("c_name") + query("c_fail_room_msg"),
			this_object() );
	receive_special_damage( special_type() , special_damage(victim));
        report(this_object(), this_object() );
        return 0;
    }
      if ( second_special_attack() ) return 1;

        tell_object( victim, query("c_enemy_msg")   );
        tell_room( environment(), 
	query("c_room_msg")+ victim->query("c_name") +query("c_room_msg2") 
        , ({ victim, this_object() }) );

        victim->receive_special_damage( special_type() ,special_damage(victim) );

	report(this_object(),victim);
	return 1;

}
