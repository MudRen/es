#include "../ekravia.h"
inherit OBJECT;

void	create()
{
//	::create();
	set_name("small copper key");
	set_short("铜制小钥匙");
	set_long("这是一把铜做的小钥匙, 钥匙柄上刻著迪诺旅店的标记。\n");
	add( "id", ({"key", "copper key"}) );
	set( "weight", 0);
	set( "unit", "把");
	set( "value", 0);
}

