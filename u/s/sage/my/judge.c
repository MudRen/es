// /d/abyss/hell/monster/judge.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
     set_level(22);
     set_name("pufan", "����");
     set_short("the assistant judge", "�ַ�����");
	set_long(
		"This is a simple monster created by npc maker.\n",
     "һ���׳գ��������Ӯ���Ͳ�Ҫ��es��\n"
	);
	set( "gender", "male" );
     set( "no_attack", 0 );
}
