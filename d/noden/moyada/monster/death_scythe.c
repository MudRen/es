#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(19);
	set_name( "Death scythe", "��������" );
	add ("id", ({ "scythe", }) );
	set_short( "��������" );
	set_long( @LONG
һ���������İ��ı���������Ϊ�õ����ɶ����˵ķ�������
LONG
	);
   set( "race", "undead" );
	set( "alignment", -1000 );
    set( "unit", "��" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 27 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 20 );
	set ("chat_chance", 5);
	set ("chat_output", ({
	  "��������˵: �������ˣ���������!\n", }) 
	);
	set ("max_hp", 1200);
	set ("hit_points", 1200);
	set ("persuing", 1);
   set("unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set ("aim_difficulty", ([ "critical" : 100, ]) );
	set_natural_weapon( 75, 40, 80 );
	set_natural_armor( 110, 50 );
    set ("weight", 150);
    set ("exp_reward", 32767 );
    set ("special_defense", 
         ([ "all":50, "none" : 25 ]) );
    set_skill("dodge",85);
    set_c_verbs( ({ "%sֱ��%s", "%s����%s", "%s��ɨ%s"}) );
    set_c_limbs( ({ "����", "����", "����", }) );
    set( "alt_corpse", MOYADA"obj/death_scythe" );
    set( "c_death_msg", "%s�����ķ��輸�£��������ϲ�����!\n");
}
