#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name("carrion creeper", "ʳ����");
	add( "id", ({ "creeper" }) );
	set_short( "ʳ����");
	set_long(
	  "�㿴��һֻʳ���棬�������������ר�ųԸ��õġ��壬�Ǵ���Ȼ�������\n"
	);
	set( "unit", "ֻ" );
	set( "alignment", 50 );
	set( "tactic_func", "wormattack" );
        set_natural_weapon(2,4,5);
	set_c_limbs( ({ "ͷ��", "����" }) );
	set_c_verbs( ({ "%s�ſ������%sҧȥ" }) );
}

int sting()
{
	object victim;

	if( random(20)>7 || !(victim= query_attacker()) ) return 0;
	tell_object( victim, 
		"ʳ����������³�һ�ɶ���������˲�һ��û���ι�ȥ��\n");
	tell_room( environment(this_object()),
		"ʳ������"+victim->query("c_cap_name")+"�³�һ�ɶ��\n",
		this_object() );
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5, 5 );
	return 1;
}
