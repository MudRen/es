#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name("bag", "�鲼��");
	set_short("a bag", "�鲼��");
	set_c_open_long("����鲼����С͵������װ����Ĵ��ӡ�\n");
	set( "weight", 20);
	set( "weight_apply", 50 );
   set( "max_load", 230 );
	set( "value", ({ 120, "silver" }));
	set( "prevent_insert",1 );
	set( "prevent_put_money", 1);
}
