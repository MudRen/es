#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "snow platemail", "ѩ��" );
	add( "id", ({ "plate", "platemail" }) );
	set_short(  "ѩ��" );
	set_long( 
             @LONG
����������ڼ���֮���Ա�ѩ֮�����Ͼ��֡��ɣ���˵��ȫ���庮����Ǳ�ѩ������
LONG
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal");
	set( "armor_class", 28 );
	set( "defense_bonus", 5);
	set( "special_defense",
	     ([ "cold":20, "fire":-5 ]) );
	set( "weight", 300 );
	set( "no_sale", 1);
	set( "value", ({ 5000, "silver" }) );
}
