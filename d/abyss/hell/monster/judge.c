// /d/abyss/hell/monster/judge.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name("judge", "�й�");
	set_short("the assistant judge", "ڤ���й�");
	set_long(
		"This is a simple monster created by npc maker.\n",
		"��λ�й����������׵����㣬��֪��������Ѫɫ����������������\n"
		"ʲ�������뷨��\n"
	);
	set( "gender", "male" );
	set( "no_attack", 1 );
}
