#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_c_open_long("�޵״��ǡ����̹������ز�֮һ������װ�����Ķ�����\n");
	set_name("bag", "�޵״�");
	set_short("�޵״�");
	set( "weight", 20);
 	set( "weight_apply", 50 );
        set( "max_load", 230 );
	set( "value", ({ 150, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}
