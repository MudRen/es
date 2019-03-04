#include "../moyada.h"
inherit MONSTER;

void create ()
{
    object amulet;
	::create();
	seteuid( getuid() );
	set_level(2);
	set_name( "bubble metal slime", "��ĭ����ʷ��ķ" );
	add ("id", ({ "slime", }) );
	set_short( "��ĭ����ʷ��ķ" );
	set_long( @C_LONG
�����������? �����? һ˫ԲԲ�Ĵ��۾�����Ŀ����㣬�������ÿɰ���
C_LONG
	);
	set( "alignment", 6000 );
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 30 );
	set_perm_stat( "karma", 30 );
	set ("max_hp", 10);
	set ("hit_points", 10);
	set_natural_weapon( 20, 4, 8 );
	set_natural_armor( 250, 100 );
	setenv( "C_MIN", "һֻ$N�������˹�����");
	setenv( "C_MOUT", "$N��������$D�������ˡ�");
	set ("unbleeding", 1);
	set ("aim_difficulty", ([ "critical" : 100, "weakest" : 100, ]) );
	set ("special_defense",
	    ([ "all" : 100, "none" : 100 ]) );
	set ("wimpy", 100);
	set_skill("dodge" ,100);
	set ("moving", 1);
    set ("weight", 100);
    set ("time_to_heal", 20);
    set ("exp_reward", 30000);
    set ("tactic_func", "cast_mela");
    set ("chat_chance",5);
    set ("chat_output", ({
      "��ĭ����ʷ��ķ������Ľ��ԣ�����Ŀ����㣬������΢Ц�ء�\n"
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
    tell_object( victim, "��ĭ����ʷ��ķ��������ǰ���³�һ�Ŵ����\n" );
    tell_room( environment(this_object()), 
      "��ĭ����ʷ��ķ����"+victim->query("c_name")+"��ǰ���³�һ�Ŵ����\n"
     , ({ victim, this_object() })
    );
    victim->receive_special_damage("fire", 10, 1 );
    return 1;
}

int catch_huntee( object who )
{
    tell_room( environment(this_object()), 
      "��ĭ����ʷ��ķ���� "+who->query("c_name")+" ֮�ᣬ���ŵ����˿�!\n"
    ,  ({ this_object(), who }) );
    tell_object( who, "��ĭ����ʷ��ķ������֮�ᣬ���ŵ����˿�!\n" );
    return 1;
}
