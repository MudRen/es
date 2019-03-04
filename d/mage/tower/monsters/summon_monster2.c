#include "mobs.h"
#include <races.h>

inherit RACE_DAEMON;

void create()
{
	::create();
	seteuid( getuid() );
	set_level(15);
	set_name( "summoned monster", "�ٻ���" );
	add ("id", ({ "summon", "monster", }) );
	set_short( "a summoned monster", "�ٻ���" );
	set_long(  @C_LONG
���޵���ħ�����г��Ĺ����ȫΪ�������˶��
C_LONG
	);
	set( "alignment", 0 );
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 26 );
	set_perm_stat( "int", 10 );
	set_perm_stat( "con", 27 );
	set_perm_stat( "piety", 10 );
	set_perm_stat( "karma", 19 );
	set ("max_hp", 600);
	set ("hit_points", 600);
	set_natural_weapon( 40, 24, 45 );
	set_natural_armor( 82, 40 );
	set ("speed", 20 );
	set ("moving", "@@query_moving" );
    set ("weight", 900);
    set ("exp_reward",6000 );
    set ("special_defense", 
         ([ "all" : 20, ]) );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical" : 75, ]) );
    set ("pursuing", 1);
    set_experience(60000);
    set_skill("dodge",70);
    set_c_verbs( ({ "%s��ץ%s", "%s��ײ%s", "%s����%s", "%s��ҧ%s", }) );
    set_c_limbs( ({ "ͷ", "����", "��" }) );
}

int query_moving()
{
    if( present( "rashudi", environment(this_object()) ) )
      return 0;
    return 1;
}

int catch_huntee( object who )
{
    if( !present( "rashudi", environment(this_object()) ) ) return 0;
    tell_room( environment(this_object()),  
    "�ٻ��޺ܲ�м����"+who->query("c_name")+
      "˵: �㻹�ҽ������빥���ҵ�������? �������ˣ�����!\n"
    ,  ({ this_object(), who }) );
    tell_object( who,      "�ٻ��޺ܲ�м������˵: �㻹�ҽ������빥���ҵ�������? �������ˣ�����!\n"
    );
    return 1;
}