#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "chaos ring", "�����" );
	add( "id", ({ "ring" }) );
	set_short( "�����" );
	set_long( 
@C_LONG
һ����ҫ��ǳ��ɫ��â�Ľ��ӣ�����ע������ʱ��ȴ�������ڲ�һƬ���䣬
���㿴�������
C_LONG
	);
	set( "unit", "ֻ" );
	set( "type", "finger" );
	set( "material", "element" );
	set( "defense_bonus", 7 );
	set( "special_defense", 
	     ([ "all":10 ]) );
	set( "weight", 5 );
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );
}
