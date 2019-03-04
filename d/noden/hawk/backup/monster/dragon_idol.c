#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "dragon idol", "���ο���" );
	add( "id", ({ "idol", "dragon" }) );
	set_short( "���ο���" );
	set_long(
		"�㿴��һ���޴�����ο��ܣ�������֫�ƺ���һЩ����������ǣ������\n"
	);
	set( "unit", "ֻ" );
	set( "race", "dragon" );
	set( "alignment", -1100 );
	set_natural_armor( 90, 40 );
	set_natural_weapon( 40, 24, 44 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 26 );
	set( "hit_points", 1300 );
	set( "max_hp", 1300 );
	set( "tactic_func", "my_tactic" );
	set( "wealth/gold", 200 );
	set_c_limbs( ({ "ͷ��", "����", "�Ȳ�", "β��" }) );
	set_c_verbs( ({ "%s������%s��ҧ", "�þ�צץ��%s" }) );
}

int my_tactic()
{
	object *victim;

	if( random(20)<3 ) {
		tell_room( environment(this_object()), 
			"\n���ο��ܷ���һ�����µĺ�������ӿ��������\���ɫ������....��\n\n",
			this_object() );
		victim = query_attackers();
		victim->receive_special_damage( "magic", 50 );
		return 1;
	}
	return 0;
}
