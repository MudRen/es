#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("shadow bag", "��Ӱ��");
	add( "id", ({ "bag" }) );
	set_short("��Ӱ��");
	set_c_open_long("����һ����Ӱ�� .���������Ҫ������������ʱ ,�㷢��������һ�����,\n"
	                "�����.\n"
	                );
	set("weight", 15);
	set("weight_apply", 40 );
	set("max_load", 300);
	set("value", ({ 1500, "silver" }));
	set("prevent_insert", 1);
	set("prevent_put_money", 1);
}
