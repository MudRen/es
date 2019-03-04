#include <mudlib.h>
#include "../../story.h"
#include <conditions.h>
#include <stats.h>
inherit MONSTER ;
int time=0;
void create ()
{
	::create();
	set_level(18);
	set_name( "The ice-monster Lady", "��������" );
	add ("id", ({ "monster","ice-monster","lady","Lady"}) );
	set_short("ѩɽ���� ��������");
	set_long(@CLONG
����ǰ��������һλ������ɴ�ĳ�����Ů�������ﲨ��С������һ��������ϧ��
���ӣ����������÷�����֬������ϸ����ͨ����¶������ѩ�ɡ��������أ�����һ
����ɴ���������￴�����������������������Ѽ���������������Բ�����ἡ����
��������˪����ֺ��������ƽֺ�����������ۣ���������֣�����������˼����
ɫ����������δ�á�
CLONG
	);
	set("gender","female");
	set("race","����");
	set_perm_stat("str", 25 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 20 );
        set_perm_stat("int", 28 );
	set("killer",1);
	set( "alignment", -1000 );
	set( "hit_points", 900 );
	set( "max_hp", 900 );
        set( "max_fp",400);
	set_natural_weapon( 35, 17, 30 );
	set_natural_armor( 85, 9 );
        set("aim_difficulty",([ 
    	  "ganglion":50,"critical":70,"weakest":30 ]) );
        set("stun_difficulty",100);
        set("unbleeding",1);
        set_skill("dodge",90);
        set_skill("parry",90);
        set_skill("dagger",90);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"ice_dagger");
        equip_armor(SWARM"ice_ring");
        set("special_defense",(["all":100,"none":40,"fire":-30]));
}
int my_tactic()
{
    int i;
    object victim,env,flowob;
    string power,name;
    if ( !victim=query_attacker() ) return 0;
    env=environment(this_object());
    name=victim->query("c_name");
    if ( time ) {
       if ( time>1 ) { 
         tell_room( env,sprintf(
            "���������ſ�����ҧס%s�Ĳ��ӣ�һƬ˱�֮����ԭ����������ȡ%s����Ѫ...\n"
            ,name,name),victim);
         tell_object(victim,"���������ſ����㲱��һҧ��������ȡ�����Ѫ...\n");
         (CONDITION_PREFIX + "bleeding")->apply_effect(victim,10,2);
       }
       else tell_room( env,"����������¶����ı���ڽǴ�أ�Ե�����Ѫ��\n");         
       time--;
       return 0;
    }
    switch( random(35) ) {
    case 0..1:
        tell_room(env,sprintf("�����������ڶ���%sʩչ���󷨣�\n",name),victim);
        tell_object(victim,"�����������ڶ���ʩչ���󷨣���\n\n");
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack","(  �㱻����������ס��  )\n");
        return 0;
    case 2..3 :
        time=6+random(1);
        break;    
    case 4..5:
       tell_room(env,sprintf("����������ǰһ�ӣ�������Ϯ��%s!\n",name),victim);
       tell_object(victim,"\n��Ļ���������һ�ɺ���ͻ�ƣ������˺����ˣ���\n\n");
       (CONDITION_PREFIX + "simple_poison")->apply_effect(victim,7,10);
    default :
        break;
    }
    return 0;
}

