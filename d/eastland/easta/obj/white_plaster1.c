#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
#include <compress_obj.h>
	set_name( "white plaster", "���ϰ�ҩ" );
	add( "id", ({ "plaster", "yun-nan white plaster" }) );
	set_short( "���ϰ�ҩ" );
	set_long(
		"�����ɶ���������ڵ����ϰ�ҩ�������ϱ�ʾ��: ����ҩ(apply)���Ͻ����á�\n"
	);
	set( "unit", "��" );
	set( "heal_apply", 5 );
	set( "duration", 30 );
	set( "weight", 15 );
	set( "value", ({ 150, "silver" }) );
}
