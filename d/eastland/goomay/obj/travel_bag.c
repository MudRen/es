#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("traveller's bag", "���д�");
	add( "id", ({ "bag" }) );
	set_short("���д�");
	set_c_open_long("����һ�ִ��͵����д�������װ�²��ٶ�����\n");
	set("weight", 30);
	set("weight_apply", 50 );
	set("max_load", 350);
	set("value", ({ 740, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
