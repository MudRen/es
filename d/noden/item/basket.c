#include <mudlib.h>

inherit CONTAINER;

void create()
{
	::create();
	set_name( "basket", "����" );
   set_short( "����" );
	set_c_open_long( "����һ����װ��������������Ȼ�����Ϊ�ֲڣ����ǿ������൱���á�\n" );
	set("prevent_put_money",1);
	set( "weight", 20 );
	set( "max_load", 140 );
	set( "value", ({ 13, "silver" }) );
}
