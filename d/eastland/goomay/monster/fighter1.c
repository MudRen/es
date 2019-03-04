#include "../goomay.h" 

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "wrestler wu-bu-la-kuei", "�ڲ�����" );
	set_short( "ˤ�����ڲ�����" );
	set_long(@C_LONG
�ڲ������Ǵ���������ˤ�Ǻ��֣���˵��������\���书\���ⲫ�ı������䶷
���ر�Զ�Ӽ�������μӡ�����һ���ʵ�ļ��⣬�����ǳ���ǿ׳�� 
C_LONG
	);
	set( "unit", "��" );
	add ("id", ({"wu","bu","la","kuei","wrestler" }) );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "kar", 20 );
	set_skill( "dodge", 80 );
	set_skill( "unarmed", 90 );
	set( "special_defense", ([ "all": 30 ]) );
	set("aim_difficulty", ([ "critical":25, "vascular":45, "ganglion":50 ]) );
	set("stun_difficulty/ma",30 );
	set( "gender", "male" );
	set( "race", "orc" );
	set( "alignment", -400 );
	set_natural_armor( 65, 27 );
	set_natural_weapon( 32, 17, 28 );
	set( "wealth/gold", 60 );
	set_c_verbs( ({ "%s��ǰһ����һ����ȭ����%s", "%s������%sһ��",
		"%s���һ������ȭ����%s", "%s��ǰһ�ݣ���%s���˶�ȥ",
		"%s���˶�����˫�Ƚ���%s", "%s������ת������������%s",
		"%sѹס%s�ļ����ͷײ��", "%s��ȭ�Խ�����ȭ��磬ֱȡ%s",
		"%s��Цһ��ͻȻ������ɨ��%s" }) );

	set( "tactic_func", "my_tactic" );
        equip_armor( Obj"stone_armband");
        equip_armor( Obj"win_head");

}

int my_tactic()
{
	object victim;
        string stat;
        int n;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_object( victim, "\n�ڲ�������һ�������ҵġ���ţ���졻������һ��ץ���˳�ȥ! \n");

	tell_room( environment(victim),"\n�ڲ�����ͻȻһ��ץס" + victim->query("c_name") + "����������ͷ��ת��������\n",
		({ victim, this_object() }) );

	switch( n= random(4) ) {
		case 0: stat = Goomay"mgate";	break;
		case 1: stat = Goomay"row14";	break;
		case 2: stat = Goomay"col22";	break;
		case 3: stat = Goomay"row13";	break;
		default : break;
	}

 victim->receive_damage(8);
 victim->move_player( stat,"*** �㿴��"+victim->query("c_name")+"��һ�����ǰ���˳�ȥ ***","");

 tell_object( victim, 
 "\n�㱻ˤ�˸�����ʺ��һЩ��Ѫ�������������˳��������ܵ����ƺ�����Ц�� \n\n");

	tell_room( environment(victim), 
		  "\n" +  victim->query("c_name") + "��������ѽ����ѽ��С����...���������Ϸ������������ǳ�����? ��ȥ����ǩ��!!! \n\n",
		({ victim, this_object() }) );
	return 1;
}
