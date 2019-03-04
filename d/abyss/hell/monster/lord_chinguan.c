// /d/abyss/hell/monster/lord_chinguan.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name("Lord Chin-Guan", "�ع���");
	add( "id", ({ "lord", "chin-guan", "chin", "guan" }) );
	set_short("Lord Chin-Guan", "�ع���");
	set_long(
		"You see the Lord Chin-Guan.\n",
		"�ع������ƹ�ɭ�޵��ڤ��������ְ�������������������������Ϊ��\n"
		"���������ܷ������������ܿ�͸���ģ����ع�����ǰû���κ�����˵\n"
		"��ƭ����\n"
	);
	set( "gender", "male" );
	set( "no_attack", 1 );
}
