#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "yellow cat", "���è" );
	add( "id", ({ "cat" }) );
	set_short( "���è" );
	set_long(
		"һֻȫ���ë�Ĵ�è�������������ף�����һֻСʨ�ӡ�\n"
	);
	set_c_limbs( ({ "����", "ǰ��", "ͷ��", "β��", "����" }) );
	set_c_verbs( ({ "%s������%sһҧ", "%s������צ��ץ%s" }) );
	set_skill( "dodge", 10 );
}
