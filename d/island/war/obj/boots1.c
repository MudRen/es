#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Leather Jackboots","Ƥ����ѥ" );
	add( "id",({ "jackboots","boots" }) );
	set_short( "Ƥ����ѥ" );
	set_long(@LONG
	����һ˫��¹Ƥ���ĳ�ѥ�����������Ƿǳ���
	����ม�
LONG
           );
	set( "unit","˫" );
	set( "weight",50 );
	set( "type","feet" );
	set( "material","leather" );
	set( "armor_class",6 );
	set( "value",({ 450,"silver" }) );
}
