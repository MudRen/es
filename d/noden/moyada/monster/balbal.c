#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(11);
	set_name( "Balbal", "�Ͷ��Ͷ�" );
	add ("id", ({ "balbal", }) );
	set_short( "�Ͷ��Ͷ�" );
	set_long( @LONG
A gargoyle with no wings.
LONG
             , @C_LONG
��Ϊ�������Թ��������Ե��, ����Ѿ��˻���ʯ���
C_LONG
	);
	set( "alignment", -1000 );
    set( "gender", "male" );
    set( "race", "daemon" );
    set( "unit", "ֻ" );
	set_perm_stat( "dex", 13 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 17 );
	set_perm_stat( "piety", 4 );
	set_perm_stat( "karma", 15 );
	set ("max_hp", 300);
	set ("moving", 1);
	set ("speed", 30);
	set ("hit_points", 300);
	set ("wealth", ([ "silver": 100 ]) );
	set_natural_weapon( 22, 12, 20 );
	set_natural_armor( 65, 20 );
    set ("weight", 600);
    set_c_limbs( ({ "����", "ͷ", "��", "��"}) );
    set_c_verbs( ({ "%s�ýǴ�%s", "%s����%s", "%s��ײ%s",}) );
    set ("exp_reward", 1450 );
    set_experience(14000);
}
