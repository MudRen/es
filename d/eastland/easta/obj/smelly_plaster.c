#include <mudlib.h>

inherit HERB;

void create()
{
        herb::create();
#include <compress_obj.h>
	set_name( "smelly plaster", "��Ƥ��ҩ" );
        add( "id", ({"plaster"}) );
	set_short( "��Ƥ��ҩ" );
	set_long("���Ź�Ƥ��ҩ�ϱ�ʾ��: �洫�ط���ר�ε������ˡ�\n");
	set( "unit", "��" );
	set( "heal_apply", 3 );
	set( "duration", 15 );
	set( "weight", 5 );
	set( "value", ({ 50, "silver" }) );
}
