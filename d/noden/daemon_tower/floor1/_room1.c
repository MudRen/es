#include <../tower.h>
void create(object ob)
{
	if ( !ob ) return ;
	ob->set_short("��ħ����");
	ob->set_long( @C_LONG_DESCRIPTION
�����Ƕ�ħ���ĵ�һ������.
C_LONG_DESCRIPTION
	);
	ob->set( "exits", ([ 
		"south" : TOWER_F1"tower_gate", 
		"north" : TOWER_F1"room2",
	]) );

	ob->set("objects",([
		"orc" : MOB"orc",
		]) );

	ob->reset();
}
