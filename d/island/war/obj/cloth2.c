#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Suntan","����" );
	add( "id",({ "suntan" }) );
	set_short( "����" );
	set_long(@LONG
	һ������ɫ�ľ�����
LONG
		);
	set( "unit","��" );
	set( "type","body" );
	set( "material","cloth" );
	set( "armor_class",20 );
	set( "defense_bonus",4 );
	set( "weight",80 );
	set( "value",({ 590,"silver" }) );
}

