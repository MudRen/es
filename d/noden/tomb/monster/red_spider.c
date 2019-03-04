#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "red spider", "��֩��" );
	add( "id", ({ "spider" }) );
   set_short( "��֩��" );
	set_long(
		"�㿴��һֻ����˶��ĺ�֩�룬����֩�벢���������������ר�����ٵ��ж�\n"
		"��ǿ������֫�岶ʳС�����ֻ֩��������Ĵ���������������ˡ�\n"
	);
   set("race","insect");
	set_perm_stat( "dex", 7 );
	set( "natural_weapon_class1", 12 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 9 );
	set( "alignment", -600 );
	set( "aggressive", 1 );
	set( "pursuing", 1 );
	set( "tactic_func", "my_tactic" );

	set( "unit", "ֻ" );
	set_c_verbs( ({ "%s������ֻ��������%sҧ��", "%s��ë���׵�ǰ֫��%sһ��",
		"%s�����ϼ����Ӳë��%s�ȥ" }) );
	set_c_limbs( ({ "ͷ��", "����", "�Ȳ�" }) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<15 || !(victim = query_attackers()) ) return 0;
    tell_room( environment(),
            "��֩��������һ�ɺ�ɫ�����壬ʹ������ֽŷ��������˯��\n" );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "poison", 16 );
	return 1;
}
