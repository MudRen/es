#include "../dony.h"

inherit MONSTER;

#include <stats.h>
#include <conditions.h>

void create()
{
	::create();
	set_level(15);
	set_name( "the younger of couples", "ӥ��" );
	add("id",({"couple","couples","younger"}) );
        set_short( "��ɽ���� ӥ��" );
	set_long(@C_LONG
��ɽ�����ڽ����ϼ���������λ, ʮ����ǰһ�ۻ�ɱΪ����ʱ�ġ��㶫������,
��������������ʿ�����ӥ������ɽ�����н�������, �������������ֵ�,����
˫�ּ������������һ�״������ַ�,������ס�������Ӿ���һ����������������
�μ�ؤ�������,˳��Ҫ������������ʿ�ֽ�һ����
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set( "time_to_heal", 7 );
	set_natural_armor( 35, 18 );
	set_natural_weapon( 40, 17 , 29);
	set("max_hp",500);
	set("hit_points",500);
	set("force_points",400);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 25 );
	set_skill( "parry",30 );
	set( "wealth/silver",150);
	set( "special_defense", ([ "all": 20 ]) );
	set( "aim_difficulty",(["critical":60,"vascular":30,"weakest":50]) );
	set("couple",1);
        set_c_verbs( ({ "%sʹ���� �� �� �� ����һʽ, ����%sҪ��",
                        "%s����Ϊ��ʹ���� �� �� �� ���ڶ�ʽ, ˫�����һ��Բ����%s",
                        "%s����һ��, �� �� �� �� ������ʽ��%s���˹���",
                        "%s�͵�ʹ���� �� �� �� ����ǿһʽ, ������Ӱ��%sֱ������"
                      }) ); 
        equip_armor(DARMOR"couple_cloak");
        set( "tactic_func", "my_attack" );
        set( "chat_chance", 20 );
        set( "att_chat_output", ({
                 "��ɽ���� ӥ�Ͽ�Ц��:����һ������,���������������ҵ����Ʒ�!! \n"
            }) );
} 

int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
        return 0;
}


int my_attack()
{ 
    object *couples,victim;
    int i;
    
    victim = query_attacker();
    if( !victim ) return 0;
    
    couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
    for( i=0; i<sizeof(couples); i++ ) {
        tell_room( environment(this_object()), couples[i]->query("c_name")+
            "ŭ��:��������������۸���,�����µ���ȥ��!!\n",couples[i]);
        couples[i]->kill_ob(victim);
    }

    if( random(20)>4 ) return 0;
    if( victim->query("stop_attack") ) return 0;
    
    tell_room( environment(this_object()),
              "\n\nӥ��ʩչ�� �� �� �� �� ����"+
               victim->query("c_name")+"�ݺݵ�ץס������������!!\n",victim);
    tell_object( victim,"\n\n"+this_object()->query("c_name")+
              "ʩչ�� �� �� �� �� ������ݺݵ�ץס,���㶯������!!\n");
    victim->block_attack(10);
    victim->set_temp("msg_stop_attack","(  �㱻��ס��,�������� !!  )\n");
    return 1;
}

