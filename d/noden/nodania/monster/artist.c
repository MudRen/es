#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "perichy", "������" );
	add( "id", ({ "artist", "court artist" }) );
	set_short( "��͢����������" );
	set_long(@CLONG
��������ŵ������������������Ĺ�͢��ʦ�������ڼƻ��⼸����Ҫ��
����ȥ���С�
CLONG
	);
	set( "race", "daemon" );
	set( "gender", "female" );
	set( "natural_weapon_class1", 24 );
	set( "natural_min_damage1", 7 );
	set( "natural_max_damage1", 15 );
	set( "alignment", 600 );
	set_skill( "parry", 70 );
	set_skill( "dodge", 70 );
	set_skill( "longblade", 70 );
	set( "exp_reward", 2200 );
}
