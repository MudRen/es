#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "black crow", "��ѻ" );
	add( "id", ({ "crow" }) );
	set_short( "��ѻ" );
	set_long(@LONG
��ֻ��ѻ�ǳ�����������һ�ɰ���һ�������ĳ嶯��
LONG
	);
	set_perm_stat( "dex", 3 );

	set( "unit", "ֻ" );
	set( "natural_weapon_class1", 3 );
	set( "natural_min_damage1", 3 );
	set( "natural_max_damage1", 5 );
	set_c_verbs( ({ "%s���¸��壬�������%s", "%s��צ����%sץ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "���" }) );
}
