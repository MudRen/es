#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name( "colorful hood", "����ͷ��" );
	add( "id", ({ "hood" }) );
   set_short( "����ͷ��" );
	set_long(
		"��������ͷ���Ѿ����ƾ��ˣ�������������һ��������\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "material", "cloth");
	set( "armor_class", 1 );
	set( "weight", 10 );
	set( "value", ({ 24, "silver" }) );
}
