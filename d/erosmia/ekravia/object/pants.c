
#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black pants", "�ڳ���" );
	add( "id", ({ "pants", "black pants" }) );
   set_short( "�ڳ���" );
	set_long( @LONG
����һ�����ʵĺ�ɫ����, ��౻����������ʽ�����
LONG
	);
	set( "unit", "��" );
	set( "type", "legs" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "weight", 20 );
	set( "value", ({ 300, "silver" }) );
}
