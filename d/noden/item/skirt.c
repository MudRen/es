#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "worn skirt", "��ȹ��" );
	seteuid(getuid());
	add( "id", ({ "skirt" }) );
   set_short( "��ȹ��" );
	set_long(
		"���ȹ���Ѿ������־��ˣ����ǿ�������Ȼ��Ǭ����\n"
	);
	set( "unit", "��" );
	set( "type", "legs" );
	set( "material", "cloth");
	set( "armor_class", 2 );
	set( "weight", 30 );
	set( "value", ({ 13, "silver" }) );
}
