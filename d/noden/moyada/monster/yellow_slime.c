#include "../moyada.h"
inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(4);
	set_name( "yellow slime", "��ɫʷ��ķ" );
	add ("id", ({ "slime", }) );
	set_short( "��ɫʷ��ķ" );
	set_long( @LONG
��ɫ������֣���������ģ��ֶ��ĵġ�
LONG
	);
   set( "race", "undead" );
	set( "alignment", -100 );
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 3 );
	set_perm_stat( "str", 2 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 3 );
	set_perm_stat( "piety", 2 );
	set_perm_stat( "karma", 30 );
	set ("max_hp", 110);
	set ("hit_points", 110);
	set_natural_weapon( 12, 5, 10 );
	set_natural_armor( 100, 10 );
	set ("time_to_heal", 6);
   set( "unbleeding ", 1 );
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set ("special_defense",
	    ([ "all" : 30, "electric" : -50, ]) );
    set ("weight", 100);
    set ("exp_reward",300 );
    set ("chat_chance",5);
    set ("chat_output", ({
      "��ɫʷ��ķ�䶯һ�£�����ʳ������������ƶ�������\n"
    }) );
    set_c_verbs( ({ "%s�䶯��%s����", "%s�˵�%s����" }) );
    set_c_limbs( ({ "����"  }) );
    set( "c_death_msg", "%sֹͣ�䶯������.....\n" );
}
