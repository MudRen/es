#include "../nodania.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("poorman child", "���˺���");
	add( "id", ({ "child" }) );
	set_short("���˺���");
	set_long(
		"���С�����������ۣ�һ˫���۾���̰����������Ŀڴ���\n"
	);
	set_skill( "dodge", 10 );
	set( "alignment", 150 );
	set( "wealth/silver", 1 );

	set( "gender", "male" );
	set( "race", "halfling" );
}
