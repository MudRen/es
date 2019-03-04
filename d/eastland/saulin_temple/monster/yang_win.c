#include "../saulin_temple.h" 

inherit MONSTER;
int i=1;
void create()
{
	::create();
	set_level(18);
	set_name( "Yang Win", "��Į��ӥ ��ʤ" );
	set_short( "��Į��ӥ ��ʤ" );
	set_long(@C_LONG
��ʤ��ס���⣬�ųơ���Į��ӥ������ӥצ�ŵ�һ���֡�����ʦ����ӥצ��\
���������Դ���ӥ��ǧ�����������׹�צ����������ʽ�������ӥ������
���������ԭ���ƺ�������������ģ�������Ϊ����צ��������?
C_LONG
	);
	set( "unit", "��" );
	add ("id", ({"yang","Yang","win","Win"}) );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 26 );
	set_perm_stat( "int", 22 );
	set_perm_stat( "kar", 10 );
	set_skill( "dodge", 100 );
	set_skill( "unarmed", 100 );
        set( "special_defense", ([ "all": 50, "monk":25 ]) );
	set("aim_difficulty", ([ "critical":25, "vascular":30, "ganglion":50, "weakest":50 ]) );
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", -400 );
	set("max_hp", 600);
	set("hit_points", 600);
	set_natural_armor( 90, 31 );
	set_natural_weapon( 55, 24, 37 );
	set( "wealth/gold", 100 );
	set_c_verbs( ({ "%s��ǰ�ɽ���һצ����ӥ����ץ��%s", "%s�����ӥ�����ٿռ�����%sһץ",
		"%s���һ������צΪ��ʹ��������һ������%s", "%s��ǰһ�ݣ�ʹ����ӥ����졻��%s���˶�ȥ",
		"%s��ɶ���������ӥ�ٿա�ץ��%s", "%s������ת������������ǧ��ֻ��צץ��%s",
		"%s��Цһ����ͻȻʹ������ӥ̽������˫צ����%s" }) );

	set( "tactic_func", "my_tactic" );
        equip_armor( SAULIN_OBJ"eagle_hat");
        equip_armor( SAULIN_OBJ"eagle_cloak");
        equip_armor( SAULIN_OBJ"eagle_bracer");

}

int my_tactic()
{
	object victim;
        string stat;
        int n;

	if( random(100)>8 ||(!i) || !(victim= query_attacker()) ) return 0;
	if( victim->query("stop_attack") ) return 0;
	tell_room( environment(this_player() ),  
set_color("\n\n��ʤͻȻ˫�۷���һ����⣬���������磬צ����ӥ����ӥ��ʽ���ϵ�춴ˡ�\n�����������������������... \n\n","HIG")   
         ); 
         
         i = 0; 
         this_player()->continue_attack();
         this_player()->continue_attack();
         this_player()->continue_attack();
         i = 1; 
	return 1;
}
