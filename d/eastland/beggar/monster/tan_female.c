#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "moon female", "������" );
	add("id",({"moon","female"}) );
        set_short( "���ɽ���ƶ� ������" );
	set_long(@C_LONG
������ԼĪ�塢��ʮ�����,���ţ��ߴ�,�׷�����,�������ƺ���������С����
������,�����Ȥ�� ���Զ�ʮ��ǰ�����������Ⱦ��ڴ��ɽ���ƶ�һֱδ����,��
����ؤ��������صظ����μ�ؤ������䡻ʢ�ᡣ
C_LONG
	);
	set( "gender", "female" );
	set( "race", "human" );
	set( "alignment", 30 );
	set_natural_armor( 40 , 40 );
	set_natural_weapon( 50 , 25 , 33);
	set("max_hp",420);
	set("hit_points",420);
	set_perm_stat( "str", 26 );
	set_perm_stat( "dex",22 );
	set_perm_stat( "int",23 );
	set_skill( "parry",35 );
	set_skill( "dodge",60 );
	set( "wealth/silver",100);
	set( "special_defense", ([ "all": 35,"none":40 ]) );
	set( "aim_difficulty",(["critical":60,"vascular":40,"weakest":40]) );
	set("couple",1);
        set_c_verbs( ({ "%sʹ������װ͡���һ��, ����%s��",
                        "%s�����������װ͡��ڶ���, ˫����%s��ȥ��",
                        "%s���һ��,����װ͡���ǿһʽžžž�������ƴ���%s��"
                      }) ); 
        set( "chat_chance", 22 );
        set( "att_chat_output", ({
                "������ŭ��:��֪С��,������������������۸���!! \n"
        }) );
                                         
        equip_armor(DARMOR"tan_ring");
        set( "tactic_func", "my_attack" );
} 

int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
        return 0;
}

int my_attack()
{ 
    object victim, *couples;
    int i;
  
    victim = query_attacker();
    if( !victim ) return 0;

    couples = filter_array( all_inventory(environment(this_object())),
        "can_help", this_object() );
    for( i=0; i<sizeof(couples); i++ ) {
         tell_room( environment(this_object()), couples[i]->query("c_name")+
            "˵��:�������ǹ���,��������?\n",couples[i]);
            couples[i]->kill_ob(victim);
    }
                                                      
    if  ( random(14)>2 )  return 0;
    else{
       tell_room( environment(this_object()),
           "��������������"+victim->query("c_name")+"һ���ϴ�����!!\n",victim);
       tell_object( victim,"����������������һ���ϴ�����!\n");
       victim->receive_damage(12);
       return 1;
   }      
}


