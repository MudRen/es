#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("basket", "����");
	set_short("����");
	set_c_open_long("����һ������õ����ӣ�����װ������\n");
	set("weight", 50);
	set("weight_apply", 80 );
	set("max_load", 150);
	set("value", ({ 40, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
