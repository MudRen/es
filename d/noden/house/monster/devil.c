#include <mudlib.h>

inherit MONSTER;
int is_zapped = 0;

void create()
{
	::create();
	set_level(13);
	set_name( "devil boy", "��ħ����" );
	add( "id", ({ "boy" }) );
	set_short( "��ħ����" );
	set_long(
		"���С�к��к�ɫ������ͺ�ɫ��ͷ�������Ķ�ͷ����һ����ħ�ı�ǣ���\n"
		"������߽Ӵ��������۾�ʱ���㿴����а���ɢ�����Ĺ�ʡ�\n"
	);
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 18 );
	set_skill( "dodge", 100 );
	set( "killer", 1 );
   set( "race", "daemon" );
	set( "gender", "male" );
	set( "alignment", -1000 );
	set( "natural_armor_class", 40 );
	set( "natural_defense_bonus", 200 );	// You need an incantation to change this *grin*
	set( "natural_weapon_class1", 25 );
	set( "natural_min_damage1", 11 );
	set( "natural_max_damage1", 20 );
	set( "tactic_func", "my_tactic" );
	set( "chat_chance", 10 );
	set( "att_chat_output", ({
		"��ħ����˵��: �ٺٺ� .... ���Ȼ�������ң��ͱ��������\n",
		"��ħ��������¶��а���Ц�ݡ�\n",
		"��ħ����Ъ˹����ط�����߽��Ĺֽ�: ɱѽ��ɱѽ��ɱѽ��\n"
	}) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<18 || !(victim = query_attackers()) ) return 0;
	tell_room( environment(this_object()), 
		"��ħ�����૵�������������ģ�ʹ����������ʹ��\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "evil", 30 );
	return 1;
}

// This function is called by the incantation of exorcise
void zapped()
{
	is_zapped = 1;
	set( "natural_defense_bonus", 20 );
	calc_armor_class();
	tell_room( environment(this_object()), 
		"��ħ����һ������ħ�䣬�������: �����ļһ���Ǹ������ÿ���\n" ,
		this_object() );
}

void die()
{
        object killer;
	killer = query("last_attacker");
	if( is_zapped ) {
		killer->set_temp("devil_killer",1);
		::die();
	}
	else {
		tell_room( environment(this_object()), 
			"��ħ����ȳ�������Ѫ�����ڵ��� ....\n\n"
			"������һ��ɳ�Ƶ������Ӷ�ħ�����ʬ�巢��: ������Ϊ���������������룡��\n\n"
			"��ħ�����ʬ����վ��������\n\n" ,
			this_object() );
		set( "exp_reward", 1 );
		set( "alt_corpse", "/d/noden/house/monster/devil" );
		::die(1);
	}
}
