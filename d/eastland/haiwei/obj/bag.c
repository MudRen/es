#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("miscellaneous bag", "�˱���");
	add( "id", ({ "bag" }) );
	set_short("�˱���");
	set_c_open_long("����˱�����������װ���ٶ�����\n");
	set("weight", 10);
	set("weight_apply", 50 );
	set("max_load", 250);
	set("value", ({ 540, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
