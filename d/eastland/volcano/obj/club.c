#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "small club", "С���" );
	set_short( "С���" );
	set_long(
"һֻСľ鳣���ֵ�������ӵ���ǰ���а���һ��������Ķ�����\n"
	);
        add( "id", ({"club"}) );
	set( "no_sale", 1 );
	set( "unit", "ֻ" );
	set( "weight", 5 );
	set( "value", ({ 1, "silver" }) );
}
