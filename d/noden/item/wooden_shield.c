#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "wooden shield", "ľ��" );
	add( "id", ({ "shield"  }) );
   set_short( "ľ��" );
	set_long(
		"һ���Ӳ��ľ�ƶ��ƣ����滭��һֻ������צ�Ļ�����\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "wood" );
	set( "weight", 60 );
	set( "armor_class", 3 );
	set( "value", ({ 60, "silver" }) );
}
