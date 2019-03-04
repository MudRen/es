#include "../saulin_temple.h"

#include <stats.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("baby mushroom", "��֥����");
	add("id",({ "baby", "mushroom" }));
	set_short("��֥����" );
	set_long(
@DESC
һֻ���ڿ���������Ҷ����֥�����������ú�����۹⿴���㡣ԭ��
����ס��һ����֥���壬���ǰ�ˮ�������ˣ��ѹ���ھ���ûˮ����
������������Ĵ�ʦ����(report)�йط�����֥(mushroom)������¡�
DESC
	);
	set("unit", "ֻ" );
	set("alignment", 250 );
	set_perm_stat("dex",10);
	set_perm_stat("str",6);
	set_perm_stat("kar",8);
	set("max_hp", 150);
	set("hit_points", 150);
	set("max_fp", 100);
	set("force_points", 100);	
	set_natural_weapon( 7, 4, 6 );
	set_natural_armor( 18, 10 );
	set("special_defense", ([ "all" : 20, ]) );
	set("unbleeding", 1);
	set("tactic_func", "sleepy" );
	set("exp_reward", 200 );
	set("alt_corpse", SAULIN_OBJ"small_pill" );
	set_c_verbs(({ "%s������ײ%s", "%s��ͷײ%s" }));
	set_c_limbs(({ "����", "ͷ��" }));
	set("chat_chance",10);
	set("chat_output",({
        "��֥����գ���ɰ��Ĵ��۾�˵�������Ǵ�Ұ���� \n",
        "��֥����գ���ɰ��Ĵ��۾�˵�����������廹�ǰ��̣�\n"
    }));
    set("c_death_msg","%sͻȻ�������������ڵ���... �����ˡ�\n");
}

int sleepy()
{
	object victim, mother;
	if( !(victim = query_attacker()) ) return 0;
	if( (mother = present("mami", environment())) &&
		((object)mother->query_attacker() != victim) ) {
		tell_object( victim, @ANGRY
		
վ������������֥����ͻȻ������צ������������һ��
�������˭���۸��ҵ�С�����������! ������!!
	
ANGRY
 		);
 		mother->kill_ob(victim);
	}	
	if( random(20)>5 ) return 0;
    if( victim->query("stop_attack") ) return 0;
    tell_object( victim,
    	"��֥����ɢ����һ����������е������˯!!\n");

    tell_room( environment(), 
    	"��֥��������"+victim->query("c_name")+"�ԵĲ������� !!\n"
		, ({ victim, this_object() })
	);
    victim->block_attack(4);
    victim->set_temp("msg_stop_attack", 
    	"( ������ȫ��������ֻ��úõ�˯һ�� ! )\n" 
    );
    return 1;
}

void die()
{
    object killer, mother;

	::die();
    killer = query("last_attacker");
	if( (int)killer->query_level() >= 5 ) {
    	tell_room( environment(this_object()), 
    		@C_DIE_MESSAGE
    		
��������֥�����������ͻȻһ��ŭ�������㱳�ᴫ������תͷһ��
ͻȻ�ֳ���һֻ��֥������������������צ������������һ�����
����������ߵȼ��˻����۸�С�����������ҵ�������!!

C_DIE_MESSAGE
			,this_object()
		);
        if( !( mother=present("mami", environment()) ) ) {
        	mother = new( SAULIN_MONSTER"big_bug" );
        	mother->move( environment(killer) );
		}        
        mother->kill_ob(killer);
	}
}
