#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "black spider", "��֩��" );
	add( "id", ({ "spider" }) );
   set_short( "��֩��" );
	set_long(
		"�㿴��һֻ��ɫ�Ĵ�֩�룬����֩�벢���������������ר�����ٵ��ж�\n"
		"��ǿ������֫�岶ʳС�����ֻ֩��������Ĵ���������������ˡ�\n"
	);
   set("race","insect");
	set_perm_stat( "str", 2 );
	set( "alignment", -300 );
	set( "aggressive", 1 );

	set( "unit", "ֻ" );
	set_c_verbs( ({ "%s������ֻ��������%sҧ��", "%s��ë���׵�ǰ֫��%sһ��" }) );
	set_c_limbs( ({ "ͷ��", "����", "�Ȳ�" }) );
}
