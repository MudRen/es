#include "../../story.h"
inherit MONSTER;
void create ()
{
	::create();
	set_level(17);
	set_name( "Iorn-fan princess", "���ȹ���" );
	add ("id", ({ "princess"}) );
	set_short( "���ȹ���");
	set_long(@CLONG
���ȹ�������ϸü��Ŀ������������������飬����������ͷ��˫�١�����һ��
�еز���Ƕ���������������������㲻�࣬�ְ����ۣ���ȥ����Ҳ�ơ��ּ�����
�����棬���ϳ���Ц�ݣ��γ�����С���У���ȥ����ʮ����⾰����Ҳ����������
�����������顣
CLONG
	);
        set("age",10);
        set( "forgetful",1);
	set("race","human");
	set("gender","female");
        set_perm_stat("str",23);
        set_perm_stat("dex",22);
        set_perm_stat("int",23);
        set("hit_points",550);
        set("max_hp",550);
        set("max_fp",300);
	set( "alignment", 500 );
	set_natural_weapon( 43, 22, 33 );
	set_natural_armor( 55, 26 );
        set("wealth/gold",50);
        set("stun_difficulty",100);
        set_skill("parry",70);
        set_skill("dodge",70);
        set_skill("blunt",70);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"p_fan1");
        equip_armor(SWARM"p_amulet1");
        equip_armor(SWARM"p_cloth1");
        set("special_defense", ([ "all": 50,"none":30]) );
        set("aim_difficulty",
            (["critical":65,"vascular":40,"ganglion":70,"weakest":65]) );
}
int my_tactic()
{
    object victim;
    string name;
    
    if ( !victim=query_attacker() ) return 0;
    if(random(17)>1) return 0;
    name=victim->query("c_name");
    tell_object(victim,"\nֻ�����ȹ������еİŽ��ȷ�������죬�漴������һ�����ǣ��ɳ����⡫��\n\n");
    tell_room(environment(victim),sprintf(
      "\nֻ�����ȹ������еİŽ��ȷ��������죬%s��ӷ�׵������漴�ɳ���������һ�����ǣ������ݡ�����֪Ҫ�����������\n\n",name),victim);
    victim->move_player(SCITY"ice1","SNEAK");
    tell_object(victim,"\n�ף��������ﰡ��\n\n");
    tell_room(environment(victim),sprintf(
        "%s��Ȼ�Ӹ߿���ˤ������������űߡ���\n",name),victim);
    victim->receive_damage(30);
    return 1;
}
