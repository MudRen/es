#include <../tower.h>

//	inherit ROOM;

void create(object ob)
{
//	::create();
	if ( !ob ) return ;
	ob->set_short("��ħ����");
	ob->set_long( @C_LONG_DESCRIPTION
�����Ƕ�ħ���ĵڶ�������.
C_LONG_DESCRIPTION
	);
	ob->set( "exits", ([ 
		"south" : TOWER_F1"room1", 
//		"north" : TOWER_F1"room1",
	]) );
/*
	ob->set("objects",([
		"orc" : MOB"orc",
		]) );
*/
	ob->reset();
}
