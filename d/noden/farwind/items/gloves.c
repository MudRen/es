#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "leather gloves", "Ƥ����" );
	add( "id", ({ "gloves" }) );
	set_short( "Ƥ����" );
	set_long(@CLONG
��˫Ƥ��������һ�����ɫ��Ƥ���Ƴɵģ�������ů�������
�����ֲ���
CLONG
	);
	set( "unit", "˫" );
	set( "type", "hands" );
	set( "material", "leather" );
	set( "armor_class", 1 );
	set( "weight", 30 );
	set( "value", ({ 110, "silver" }) );
}
