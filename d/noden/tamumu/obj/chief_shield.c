#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "totem shield", "ͼ�ڶ�" );
	add( "id", ({ "shield" }) );
	set_short( "ͼ�ڶ�" );
	set_long(@C_LONG
���������ĳ�����û���������ؽ����Ƴɵģ����滭���˸���ɫ������
�ķ�����ͼ�Σ���ս���п����õ�������η�塣
C_LONG
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material", "light_metal" );
	set( "armor_class", 7 );
	set( "special_defense", ([ "mental":5 ]) );
	set( "weight", 180 );
	set( "value", ({ 1750, "silver" }) );
}
