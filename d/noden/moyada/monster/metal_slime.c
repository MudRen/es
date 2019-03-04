#include "../moyada.h"
inherit MONSTER;

void create ()
{
    object amulet;
	::create();
	seteuid( getuid() );
	set_level(1);
	set_name( "metal slime", "����ʷ��ķ" );
	add ("id", ({ "slime", }) );
	set_short( "����ʷ��ķ" );
	set_long( @LONG
�����������? �����? һ˫ԲԲ�Ĵ��۾�����Ŀ����㣬�������ÿɰ���
LONG
	);
   set( "race", "undead" );
	set( "alignment", 4000 );
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 1 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 1 );
	set_perm_stat( "piety", 30 );
	set_perm_stat( "karma", 30 );
	set ("max_hp", 5);
	set ("hit_points", 5);
	set_natural_weapon( 15, 3, 6 );
   set_natural_armor( 250, 100 );
	setenv( "C_MIN", "һֻ$N�������˹�����");
	setenv( "C_MOUT", "$N��������$D�������ˡ�");
   set("unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set ("aim_difficulty", ([ "critical" : 100, "weakest" : 100, ]) );
	set ("special_defense",
        ([ "all" : 100, "none" : 35 ]) );
	set ("wimpy", 5);
	set_skill("dodge", 100);
	set ("moving", 1);
    set ("weight", 100);
    set ("time_to_heal", 40);
    set ("exp_reward", 15000);
    set ("tactic_func", "cast_mela");
    set ("chat_chance",5);
    set ("chat_output", ({
      "����ʷ��ķ������Ľ��ԣ�����Ŀ����㣬������΢Ц�ء�\n"
    }) );
    set_c_verbs( ({ "%sײ��%s����", "%s�˵�%s����" }) );
    set_c_limbs( ({ "����"  }) );
    set( "c_death_msg", "%s˵: Ϊʲ��Ҫ���� .... Ȼ������ˡ�\n" );
    equip_armor( MOYADA"obj/slime_amulet" );
}

void cast_mela()
{
    object victim;
    if( !(victim=query_attacker()) || random(10)> 1 ) return 0;
    tell_object( victim,
      "����ʷ��ķ��������ǰ���³�һ��С����\n" );
    tell_room( environment(this_object()), 
      "����ʷ��ķ����"+victim->query("c_name")+"��ǰ���³�һ��С����\n"
     , ({ victim, this_object() })
    );
    victim->receive_special_damage("fire", 5, 1 );
}

int catch_huntee( object who )
{
    tell_room( this_object(), 
      "����ʷ��ķ���� "+who->query("c_name")+" ֮�ᣬ���ŵ����˿�!\n"
   ,  ({ this_object(), who }) );
    tell_object( who, 
      "����ʷ��ķ������֮�ᣬ���ŵ����˿�!\n" );
    return 1;
}
