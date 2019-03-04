// ���������⹥���ο� : Weapon's special attack inherit
// Code by : Ruby of ES at 7/30/94 
// ע�� : ����(inherit)����ʽ�ᣬҪ�ڳ�ʽ���ж������⹥���Ĳ���
// ��:	set("special_attack",(["damage_type" : "none","main_damage" : 10,
//				"random_dam" : 5 , "hit_rate" : 20]));
//	  set("hit_func","special_attack");
// �����������ѶϢ��������Ӣ�ĵ� msg,enemy_msg,fail_msg,fail_room_message
// ���˸���

#include <mudlib.h>
inherit WEAPON;

// ��ʾ����������������� : write by Echobomber

void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim)));
   return ;
}

// ���������ڶ���ʽ���ɱ����¶��������ӱ仯�ԡ�

// ʹ�����⹥��ʧ�ܶ��ⷴ�������� : fail_to_use()
int fail_to_use()	{ return 0; }

// ���⹥���ĳ��ֻ���  : special_hit_rate()
int special_hit_rate()	{ return (int)query("special_attack/hit_rate") ; }

// ���⹥������ɵ��˺� : special_damage() 
int special_damage()	{ return (int)query("special_attack/main_damage")+
				random(query("special_attack/random_damage")) ; }

// �����˺������� : special_type() ������ 11 ��
// Ϊ : fire,code,electric,energy,mental,acid,poison,magic,evil,divine,none
string special_type()	{ return (string)query("special_attack/damage_type") ; }

// �ڶ������⹥��Ԥ���� : �����ٶ���һ�����ϵ����⹥����̬
int second_special_attack() { return 0 ; }

int special_attack(object victim,int damage)
{
	object holder;
	string type ;

    if ( !victim ) return 0;
    if( !(holder = environment(this_object())) || !living(holder) ) return 0;

    if ( fail_to_use() ) {
                tell_room( environment(holder), 
			holder->query("c_name") + query("c_fail_room_msg"),
                        holder );
		tell_object( holder, query("c_fail_msg") );

	holder->receive_special_damage( special_type() , special_damage());
	report(holder,holder);
	return 0;
	}

      if ( second_special_attack() ) return 1;
      if ( random(100) < special_hit_rate() )  {
	victim->receive_special_damage( special_type() ,special_damage() );
                tell_object( holder,query("c_msg") );

                tell_object( victim , 
		holder->query("c_name") + query("c_enemy_msg") );
		report(holder,victim);

	return 1;
	}
	
      return 0;
}
