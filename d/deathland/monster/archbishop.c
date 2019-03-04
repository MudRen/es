#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create ()
{

	::create();
	seteuid( getuid() );
    set_level(19);
    set_name("archbishop Desyer","�����̵�˹�˶�");
    add("id",({"dwarf","bishop","desyer"}) );
    set_short("Archbishop Desyer","�����̵�˹�˶�");
	set_long(
@C_LONG
���˴�����,��������.���޷��²��������,��Ϊ����һ�����˵ķ�ɼ���ͷ��
�׷�,����֮�����Ŀڲ�Ҳ��һ����.ÿ�����ڴ�����ʱ��,�������ǳ������˳�.
C_LONG
	);
    set("weapon_master",1);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "��" );
    set_perm_stat( "dex",19);
    set_perm_stat( "str",18);
    set_perm_stat( "int",28);
    set_perm_stat( "con",20);
    set_perm_stat( "piety",27);
    set_perm_stat( "karma",26);
	
    set ("max_hp",690);
    set ("max_sp",630);
    set ("hit_points",690);
    set("spell_points",630);
    set ("wealth", ([ "gold":3]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(70,48);
	set ("aim_difficulty",([ "critical":33,"vascular":38]) );
        set("special_defense", (["all":45,"none":70,"monk":20,"scholar":20]) );
    set ("weight", 440);
    equip_armor(Armour"/cloth02");
    wield_weapon(Weapon"/blackmace");
    equip_armor(Armour"/cloak01");
    equip_armor(Armour"/amulet02");
    equip_armor(Armour"/ring01");
    set( "inquiry", ([
         "yang" : "@@ask_yang",
         "lucksis" : "@@ask_lucksis",
         ]) );
    set( "tactic_func", "cast_spell");
}

void ask_yang(object who)
{
     tell_object( who , @MSG1
   ��˵�еĶ��� Evil Yang,һ��ӵ�����Ϸ�������. ���ݹ��ϵĴ�˵��Ϊ��
�ܹ���Խ�������е���,���Լ����춺ڰ�����Ԩ֮��.
MSG1
       ); 
}

void ask_lucksis(object who)
{
     if (!(who->query_temp("lucksis_quest")) || (int)(who->query_temp("lucksis_quest/ask"))==0 ) 
       tell_object(who,"��˹�˶��������������������\n"
                       );
     else
       {
         tell_object(who,@MSG2
��˹�˶�˵:��������ϣ˿������?
�����Ҽ�����������˭,��Ϊ���� Yang ��ʹ��.
�ҵ�ְ����ǰ��� Yang �� ��ͽ.
��˹�˶�΢Ц�Ŀ�����˵:Ҫ����һ������?


�����˹�˶�����ְ��Ա,���������������ϣ˿������һ����ܻ�
���һ����.
MSG2
                    );
         who->set_temp("lucksis_quest/desyer",1);             
       }
     return;
}

int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 3 ) {
      tell_room( environment(this_object()), 
        sprintf("�����̵�˹�˶���� : Yang ���ݻ�������\n\nһ��ǿ���Ȼ����%s�������.\n\n",c_name) );
      victim->receive_special_damage("divide", 40+random(25));
      report(this_object(),victim);
      return 1;
    }
   if(  random(10) < 3 && victim->query_temp("cast_busy") ) {
        tell_object(victim,
               "�����̷�������ʹ��ħ��,��ǿ�ʼʩչ����ħ��\n"
               );
        tell_room(environment(this_object()),
          sprintf("�����̵�˹�˶���ħ��������%s�����\n" ,c_name));
        victim->receive_damage(90-(int)(victim->query_stat("kar")));  
        report(this_object(),victim);
        return 1;
    }
    return 0;
}

