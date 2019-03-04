#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(15);
	set_name( "daemon shadow", "��ħ" );
	add ("id", ({ "daemon", "demon", }) );
	set_short( "��ħ" );
	set_long( @C_LONG
�����ڤ�ڵ�����Ķ�ħ����ħ��ĵ�λ�ĸߣ�������������ص�
Ϊ�����������������˵�����������ݡ�
C_LONG
	);
	set ("alignment", -2000 );
    set ("unit", "ֻ" );
    set ("race", "daemon");
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 27 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 25 );
	set ("c_death_msg", "%s���һ��:%#$@&*@*!%&&(��������������������).... Ȼ�������!\n" );
	set ("max_hp", 1000);
	set ("hit_points", 1000);
	set ("persuing", 1);
	set ("time_to_heal", 3);
	set ("aggressive", 1);
	set ("aim_difficulty", ([ "critical" : 50, ]) );
	set ("unbleeding", 1);
	set_natural_weapon( 40, 15, 20 );
	set_natural_armor( 70, 30 );
    set ("weight", 400);
    set ("exp_reward", 9000 );
    set ("special_defense", 
         ([ "all":35 ]) );
    set_skill("shortblade", 80);
    set_experience(20000);
    set_skill("dodge",70);
    set_c_verbs( ({ "%s��צ��ץ%s", "%s�ýǴ�%s", "%s��%s",
                    "%sҧ%s", "%s��������������%s", }) );
    set_c_limbs( ({ "ͷ", "����", "��", "��", "���", }) );
    wield_weapon(MOYADA"obj/d_death_scythe");
}

void die()
{
	object killer;

	killer = query("last_attacker");
	if( killer ) killer->set_temp("wanfu/done",1);
	::die();
}
