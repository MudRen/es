#include "../takeda.h" 

inherit "/d/eastland/liang_shan/monster/liang_shan_bandit";

void create()
{
	::create();
	set_level(16);
	set_name( "Song Jiang", "�ν�" );
	set_short( "�ν�" );
	set_long(
@C_LONG
    ���ֹ�������ź����壬�˳Ƽ�ʱ���ι�����۩�����μҴ��ˡ��׹���ʷ��
����Ȩı��������Т��������ƣ�Ϊ��ɽ���ܱ���ͷ�죬�������ǣ��𶯾�ʦ��
C_LONG
	);
	set( "unit", "��" );
	add ("id", ({"song","jiang" }) );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int", 27 );
	set_perm_stat( "kar", 28 );
	set_skill( "dodge", 100 );
	set_skill( "unarmed_parry",100 );
	set_skill( "unarmed", 100 );
	set( "time_to_heal",2 );
	set( "special_defense", ([ "all": 50 ]) );
	set("aim_difficulty", ([ "critical":30, "vascular":55, "ganglion":50 ]) );
	set("stun_difficulty/ma",40 );
	set( "gender", "male" );
	set( "race", "human" );
	set_temp("detect_invi", 1);
	set_temp("effect/detect-invis", 1);
	
	set_temp("detect_hide", 1);
        set_temp("effect/detect-hide", 1);
	set( "alignment", 2400 );
	set_natural_armor( 70, 30 );
	set_natural_weapon( 45, 25, 38 );
	set( "defense_type","berserk");
	set( "wealth/gold", 160 );
	set_c_verbs( ({ "%s��̬������Ȼ, �����Ŀ���%s",
		"%s���ֶ���, ����%s��������΢Ц", "%s����ҡͷ, ��������%s",
		"%sһ����Х, %s�о�һ������"
		 }) );

	set( "tactic_func", "my_tactic" );
        equip_armor( TARMOR"phoenix_helmet");
        equip_armor( TARMOR"waterlily_boots");
        equip_armor( TARMOR"gold_chainmail");
        equip_armor( TARMOR"hoshi_jade");

}

int my_tactic()
{
	object victim,bandit;
        string stat;
        int n;

	if( random(5)>1 || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	if( victim->query_temp("caught") < 3 ) {
	victim->add_temp("caught",1) ;
	tell_object( victim, 
"\n�ν�̾��: ����˵�����, ��������, ����������, ��������һ��! \n"
"����һ����·����.......\n\n"
"�ν��ӻ���, һȺ��ް��������կ��, Ȼ��һ�ѽ����Ƶ��ڵ�\n");
	tell_room( environment(), 
"\n�ν��ɳ�һ����ް�" + victim->query("c_name") + "��̧���𴦷���\n",
		 this_object()  );

 victim->receive_damage(5);
 victim->move_player( TROOM"gate1","*** �㿴��"+victim->query("c_name")+"��һֻ���㱻�˶����� ***","");

 tell_object( victim, 
 "\n�㱻ˤ�˸�����ʺ��һЩ��Ѫ�������������˳��������ܵ����ƺ�����Ц�� \n\n");
	return 1;
}
        tell_object( victim,
        "\n�ν����: �����������ֻ���, ������޷���������? \n\n"
        "�ν��ӻ���, һȺ��ް���ץȥ����, Ȼ��һ�ѽ����Ƶ��ڵ�\n");
        tell_room( environment(),
        "\n�ν��ӻ��֣�һ����ް�" + victim->query("c_name") + "���ൽ���ζ���˽��...\n",
                 this_object()  );
        victim->receive_damage(30);
        bandit = new(TMONSTER"small_bandit");
        
 victim->move_player( TROOM"jail1","*** �㿴��"+victim->query("c_name")+"��һֻ���㱻�˶����� ***","");
 bandit->move(environment(victim));
 bandit->kill_ob(victim);
 tell_object( victim,
  "\n�㱻ˤ�˸�����ʺ��һЩ��Ѫ�������������˳��������ܵ����ƺ�����Ц�� \n\n");
 return 1;  

}