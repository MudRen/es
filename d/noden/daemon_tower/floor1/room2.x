#include <../tower.h>

inherit ROOM;

void create()
{
	::create();
//	if ( !ob ) return ;
	set_short("��ħ����");
	set_long( @C_LONG_DESCRIPTION
�����Ƕ�ħ���ĵڶ�������.
C_LONG_DESCRIPTION
	);
	set( "exits", ([ 
		"south" : TOWER_F1"room1", 
//		"north" : TOWER_F1"room1",
	]) );
/*
	ob->set("objects",([
		"orc" : MOB"orc",
		]) );
*/
	reset();
replace_program(ROOM);
}