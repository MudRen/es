#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Armbands","ս��ۻ�" );
	add( "id",({ "armbands" }) );
	set_short( "ս��ۻ�" );
	set_long(@LONG
	����ս�������䱸�еıۻ���
LONG
           );
	set( "unit","˫" );
	set( "weight",10 );
	set( "type","arms" );
	set( "material","heavy_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",4 );
	set( "value",({ 2100,"silver" }) );
//	set( "no_sale",1 );
}