#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "steel platemail", "�ֿ���" );
	add( "id", ({ "plate", "platemail" }) );
	set_short( "�ֿ���" );
	set_long(
		"����һ�׸��Ƶ����ؿ��ף���������Ȼ�أ�ȴ���ṩ�൱�õķ�������\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 33 );
	set( "weight", 320 );
	set( "value", ({ 2500, "silver" }) );
}
