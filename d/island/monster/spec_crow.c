#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(4);
	set_name("spectral crow", "������ѻ");
	add( "id", ({ "crow" }) );
	set_short( "������ѻ");
	set_long(@LONG
�㿴��һֻ����ʮ��ģ���ĺ�ɫ��ѻ��һ�ֲ����Ԥ�и�����������а��Ļ���
LONG
	);
	set( "unit", "ֻ" );
	set( "alignment", -300 );
	set_natural_armor( 10, 1 );
	set_natural_weapon( 7, 3, 8 );
	set_perm_stat( "int", 14 );
	set_perm_stat( "pie", 2 );
	set_perm_stat( "str", 5 );
	set( "aggressive", 1 );
	set( "tactic_func", "cry" );
	set_c_limbs( ({ "ͷ��", "����", "���" }) );
	set_c_verbs( ({ "%s������%s����һ��", "%s��צ����%sץȥ" }) );
}

int cry()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
	tell_room( environment(this_object()), 
		"������ѻ����һ�������Ľ������ŵ����ֽŷ��� ....\n",
		this_object() );
	WEAK->apply_effect( victim, 10 , 1 );
	return 1;
}
