#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "huge spider", "��֩��" );
	add( "id", ({ "spider" }) );
   set_short( "��֩��" );
	set_long(
		"�㿴��һֻ����˶���֩�룬����֩�벢���������������ר�����ٵ��ж�\n"
		"��ǿ������֫�岶ʳС�����ֻ֩��������Ĵ���������������ˡ�\n"
	);
   set("race","insect");
	set_perm_stat( "dex", 5 );
	set( "natural_weapon_class1", 7 );
	set( "natural_min_damage1", 4 );
	set( "natural_max_damage1", 6 );
	set( "alignment", -300 );
	set( "aggressive", 1 );
	set( "tactic_func", "my_tactic" );

	set( "unit", "ֻ" );
	set_c_verbs( ({ "%s������ֻ��������%sҧ��", "%s��ë���׵�ǰ֫��%sһ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "�Ȳ�" }) );
}

int my_tactic()
{
	object *victim;
	int i;

	if( random(20)<15 || !(victim = query_attackers()) ) return 0;
   tell_room( environment(),
             "��֩��������һ�ɻ�ɫ�����壬ʹ�����ͷ�����ͣ���ҪŻ�£�\n" );
	for( i=0; i<sizeof(victim); i++ )
		victim[i]->receive_special_damage( "poison", 10 );
	return 1;
}
