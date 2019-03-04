#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(9);
	set_name( "Gargoyle", "ʯ���" );
	add ("id", ({ "gargoyle", }) );
	set_short( "ʯ���" );
	set_long( @C_LONG
��ʹ�ñ����ĳ��������з���, �����Ƚ�ϲ����ס�ںڰ��Ľ���. ��ʹ��
ͷ�ϵ���ֻ��, ��������. 
C_LONG
	);
	set( "alignment", -600 );
    set( "gender", "male" );
    set( "race", "daemon" );
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 14 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 7 );
	set_perm_stat( "con", 13 );
	set_perm_stat( "piety", 5 );
	set_perm_stat( "karma", 10 );
	set ("max_hp", 250);
	set ("hit_points", 250);
	set ("wealth", ([ "silver": 60 ]) );
	set_natural_weapon( 19, 10, 18 );
	set_natural_armor( 55, 20 );
    set ("weight", 550);
    set_c_limbs( ({ "����", "ͷ", "��", "��"}) );
    set_c_verbs( ({ "%s�ýǴ�%s", "%s����%s", "%s��ײ%s",}) ); 
    set ("exp_reward", 950 );
    set_experience(10000);
}
