#include "../oldcat.h"
#include "/include/move.h"
inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Leeng Ru Shuang", "�������������˪" );
	set_short( "�������������˪" );
        add ( "id", ({"shuang"}));
	set_long(@LONG
�����һ��������Ů�ˣ�����Ҳ�Ǹ���Ѫ��Ů�ˣ����������ϵĶ�����������
�κ��ֶΣ�����ҪŪ���֡�
LONG
	);
	set( "gender", "female" );
	set( "alignment", -2000 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "kar", 25 );
	set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
	set_skill( "shortblade",90);
	
	set( "hit_points" , 600);
	set( "max_hp" , 600);
	set( "tactic_func", "my_tactic" );
	set_natural_armor(80,16);
	set( "special_defense",(["all":25,"none":30]) );
	set( "aim_difficulty", ([ "vascular":20,"weakest":20]) );
	set_natural_weapon(5,7,10);
        set( "killer" , 1 );
        set("chat_chance",5);
        set("att_chat_output", ({
          "\n����˪��Ц����������ƾ�㣬Ҳ����ǿ�ᱦ�У���ֱ�������Ρ�\n\n"
        }) );
        wield_weapon(OWEAPON"shortsword2");
        equip_armor(OARMOR"ring3");
        equip_armor(OARMOR"amulet2");
}

int my_tactic()
{
	object victim;
        object *all_vic;
	int i;
	
	if( random(20)>6 || !(victim= query_attacker()) )  return 0;
	if ( random(10)>5 ) {
	  if( victim->query("stop_attack") ) {
	     tell_object( victim, 
		 "\n����˪��ʧ������ǰ��������֪��ȥ�εط�ʱ��ͻȻһ�����㱳�̡�\n\n");
	     tell_room( environment(this_object()), 
		 "\n����˪��ʧ������ǰ��ͻȻһ�����̹���"+ victim->query("c_cap_name") +".\n\n"
		 ,({ victim, this_object() }) );
	     victim->receive_special_damage( "energy" , 35+random(15) );
	  }
	  else {  
	     tell_object( victim, 
		   "\n����˪ʩչ��Ǵ󷨣��㱻����ħ�����Ի�ס\n\n");
	     tell_room( environment(this_object()),
		   "\n����˪��"+ victim->query("c_cap_name") +"ʩչ��Ǵ󷨣���"+ victim->query("c_cap_name") +"���Ի�ס��.\n\n"
		   ,({ victim, this_object() }) );
	     victim->block_attack(6);
	     victim->set_temp("msg_stop_attack",
		 "( �����ڱ��Ի������޷������� )\n" );
	  }
	  return 1;
      }
      else if ( random(10)< 6 ) {
        all_vic=query_attackers();
        all_vic->receive_special_damage("mental",50 );
        tell_room(environment(),
                "\n����˪ʩչ����󷨣���ȡ���������\n\n"
                ,this_object() );
        return 1; 
      }
      else 
        return 0;  
}

void die()
{
  object ob1,killer;
 
  ob1=new(OOBJ"dragon_box");
  killer=query("last_attacker");
  killer->set_temp("dragon_box",1);
  if (!killer) {
    ::die();
    return;
  }
  tell_object(killer,
     "\n����˪��ʣ�µ�����һ��������˵���Һò�����̽�ú������������ھ�����\n"
       "��������ʹ�������˾�������������ð������Σ��Ǳ����������ѱ���͵��\n"
       "�����о�Ϊʲ����д�˵��ǿ����������벻�����ҵĴ����������޷�����\n"
       "�������������㣬����˥���ҿ���Ҳ�����ǵģ��������ҵõ����е����ܵ�\n"
       "�����������������������Ӣ�ţ�����������������������Ŀ��\n\n"
       "ֻ����˵������������ˣ������������ҵ��˺������С�\n");
  ob1->set("killer",(string)killer->query("name"));
  if ( (int)(ob1->move(killer)) != MOVE_OK )
    ob1->move(environment(this_object()));
  ::die();
}
