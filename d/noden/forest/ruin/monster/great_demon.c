#include "../ruin.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(16);
	set_name( "great demon", "���ħ" );
	add ("id", ({ "daemon", "demon", }) );
	set_short( "���ħ" );
	set_long( @C_LONG
��ħ��ڤ�ڵ�������������Ķ�ħ����ħ��ĵ�λ�ĸߣ�������������ص�
Ϊ�����������������˵�����������ݡ�
C_LONG
	);
	set( "alignment", -1500 );
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 24 );
	set_perm_stat( "con", 22 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 25 );
	set ("max_hp", 720);
	set ("hit_points", 720);
	set ("persuing", 1);
	set ("aggressive", 1);
	set ("killer", 1);
	set_natural_weapon( 45, 20, 35 );
	set_natural_armor( 85, 35 );
    set ("weight", 400);
    set ("exp_reward",10000 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":50, "weakest":40, "ganglion":20, ]) );
    set ("special_defense", 
         ([ "fire":25, "cold":25, "enerage":25, "electric":25, ]) );
    set_experience(20000);
    set_skill("dodge",70);
    set_c_verbs( ({ "%s��צ��ץ%s", "%s�ýǴ�%s", "%s��%s",
                    "%sҧ%s", "%s����������%s", }) );
    set_c_limbs( ({ "ͷ", "����", "��", "��", "���", }) );
    wield_weapon( OBJ"scythe" );
}
