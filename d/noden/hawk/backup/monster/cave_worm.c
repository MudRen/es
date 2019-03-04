#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "cave worm", "��Ѩ��" );
	add( "id", ({ "worm" }) );
	set_short( "��Ѩ��" );
	set_long(@CLONG
����һ�ֽ�����Ѩ����׳棬�������ϳ�������Ӳ�ĸ�ë��Ƥ���ϸ�����
һ����ʯ��Ľ��ʣ���˵���Ľ�����ʹ��ɥʧ������
CLONG
	);
	set( "unit", "ֻ" );
	set( "alignment", 100 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 5 );
	set_perm_stat( "dex", 2 );
	set_perm_stat( "str", 4 );
	set( "hit_points", 300 );
	set( "max_hp", 300 );
	set( "natural_armor_class", 80 );
	set( "tactic_func", "my_tactic" );
	set_c_limbs( ({ "����" }) );
	set_c_verbs( ({ "%s�ſ�������������������%s", "������ĸ�ë��%s��ȥ" }) );
}

int my_tactic()
{
	object *victim;

	if( random(20)<3 ) {
		tell_room( environment(this_object()), 
			"��Ѩ�淢��һ���ٹ����ٹ����Ľ����������һ��ͷ��....��\n",
			this_object() );
		victim = query_attackers();
		if ( victim->query("spell_points"))
			victim->set( "spell_points", 0 );
		return 1;
	}
	return 0;
}

