#include <mudlib.h>

inherit HERB;

void create()
{
	herb::create();
#include <compress_obj.h>
	set_name( "plaster", "��ҩ" );
	set_short( "��ҩ" );
	set_long("��н�ҩ�ϱ�ʾ��: ����ҩ(apply)���Ͻ����á�\n");
	set( "unit", "��" );
	set( "heal_apply", 3 );
	set( "duration", 20 );
	set( "weight", 15 );
	set( "value", ({ 6, "gold" }) );
}
