#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "ugly toad", "���" );
	add( "id", ({ "toad" }) );
	set_short( "���" );
	set_long(
		"�ִ��ֳ���󡣬������ɫ�����Ƥ����\n"
	);
	set_c_limbs( ({ "����", "ͷ��", "����" }) );
	set_c_verbs( ({ "%s������%sһҧ", "%s��������ͷ��%sһ��" }) );
}
