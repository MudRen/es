#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "zombie", "��ʬ" );
   set_short( "��ʬ" );
	set_long(
		"һ���ֳ����׶�Ľ�ʬ��\n"
	);
   set( "race", "undead" );
	set( "gender", "male" );
	set( "alignment", -400 );
	set( "aggressive", 1 );
	set( "tactic_func", "my_tactic" );
	set_c_verbs( ({"%s�����Ľ�ֱ��צ��ץ��%s", "%s�ſ�����%sҧȥ",
		"%s��ָ�ſ�����Ȼ��%s����" }) );
}

int my_tactic()
{
	object victim;
	int dam;

	if( !(victim= query_attacker()) || (random(20)>2) ) return 0;
    tell_room( environment(),
            "��ʬ���з���һЩ������ʹ�����һ����ѣ....���������������ˡ�\n",
		this_object() );
	dam = 15 + random(10);
	victim->receive_special_damage( "evil", dam );
	receive_healing( dam );
	return 1;
}

