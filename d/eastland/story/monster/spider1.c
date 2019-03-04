#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "poison spider", "����" );
	add ("id", ({ "spider" }) );
	set_short( "����" );
	set_long(@C_LONG
һֻȫ���߲ʰ�쵵ľ���֩�룬��ȫ��ë���޵ģ�������ֻ��������צ������ǰ��
����ȥ�ģ������ֿɲ����ˡ��ഫ������ϲ����û�����̺��������ȵش���������
�ܶ�����Ĺ����������ɥ����������צ֮�¡�
C_LONG
	);
        set("killer",1);
        set( "alignment",-1000);
        set( "unit", "ֻ" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 28 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "karma", 30);
	set_skill("dodge",100);
	set("special_defense", (["sleet":-25,"none":60,"fire":100]) );
        set("aim_difficulty",([
           "critical":100,"ganglion":30 ]) );
	set("max_hp", 1000);
	set("hit_points", 1000);
	set("max_fp",500);
	set_natural_weapon(57,35,53);
	set_natural_armor(70,1);
        set ("weight", 1000);
        set_c_verbs( ({ "%s������ֻ��������%sҧ��",
                        "%s��ë���׵�ǰ֫��%sһ��" }) );
        set_c_limbs( ({ "ͷ��", "����", "�Ȳ�" }) );
        set( "tactic_func", "my_tactic" );
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(15) > 2 ) return 0;
    tell_room(environment(this_object()),sprintf(
      "�����³���������˿��ס%s��\n",victim->query("c_name")),victim);  
    tell_object(victim,
      "\n�����³���������˿��������һ�������������Ѽ�����\n\n");
    (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5 , 5 );
    victim->block_attack(4);
    victim->set_temp("msg_stop_attack",
        "(  �㱻��ס�ˣ��������ã���  )\n");
    return 0;
}