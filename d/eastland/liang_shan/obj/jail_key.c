#include "../takeda.h"

inherit OBJECT;

void create()
{
	set_name( "jail key", "����Կ��" );
	add( "id", ({ "key" }) );
	set_short( "a jail key", "����Կ��" );
	set_long(
		"This is the key of Liang Shan jail.\n",
		"����һ����ʯ���ɵ�Կ�ף��������ϸе������⡣\n"
	);
	set( "to_lock", "LiangShankey-1" );
	set( "weight", 3 );
	set( "value", ({ 30, "silver" }) );
	set( "no_sale", 1 );
}
