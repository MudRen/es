#include <mobs.h>
#include <races.h>

inherit RACE_DAEMON;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(10);
	set_name( "summoned monster", "�ٻ���" );
	add ("id", ({ "summon", "monster", }) );
	set_short( "a summoned monster", "�ٻ���" );
	set_long( @C_LONG
���޵���ħ�����г��Ĺ����ȫΪ�������˶��
C_LONG
	);
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 17 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 22 );
	set_perm_stat( "piety", 5 );
	set_perm_stat( "karma", 15 );
	set ("max_hp", 280);
	set ("hit_points", 280);
	set_natural_weapon( 27, 14, 25 );
	set_natural_armor( 63, 25 );
    set ("weight", 900);
    set ("exp_reward",1500 );
    set ("speed", 20 );
    set ("moving", "@@query_moving" );
    set ("special_defense", ([ "all" : 10, ]) );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical" : 50, ]) );
    set_skill("dodge",50);
    set_c_verbs( ({ "%s��ץ%s", "%s��ײ%s", "%s����%s", "%s��ҧ%s", }) );
    set_c_limbs( ({ "ͷ", "����", "��", }) );
}

int query_moving()
{
	if( present( "rashudi", environment(this_object()) ) ) return 0;
	return 1;
}

int catch_huntee( object who )
{
    if( !present( "rashudi", environment(this_object()) ) ) return 0;
    tell_room( environment(this_object()), 
      "�ٻ��޺ܲ�м����"+who->query("c_name")+
      "˵: �㻹�ҽ������빥���ҵ�������? �������ˣ�����!\n"
    ,  ({ this_object(), who }) );
    tell_object( who,   "�ٻ��޺ܲ�м������˵: �㻹�ҽ������빥���ҵ�������? �������ˣ�����!\n"
    );
    return 1;
}
