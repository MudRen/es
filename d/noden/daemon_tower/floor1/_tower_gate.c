#include <../tower.h>
void create(object ob)
{
	if (!ob) return;
	ob->set_short("��ħ������");
	ob->set_long( @C_LONG_DESCRIPTION
�����Ƕ�ħ���Ĵ���.
C_LONG_DESCRIPTION
	);

	ob->set( "exits", ([ 
		"south" : "/u/r/ruby/rooms/workroom", 
		"north" : TOWER_F1"room1",
	]) );
	ob->reset();
}
