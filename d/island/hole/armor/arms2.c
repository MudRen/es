#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Armbands","����ʶ��ۻ�" );
	add( "id",({ "armbands" }) );
	set_short( "����ʶ��ۻ�" );
	set_long(@LONG
	�ۻ���
LONG
           );
	set( "unit","˫" );
	set( "weight",8 );
	set( "type","arms" );
	set( "material","light_metal" );
	set( "defense_bonus",2 );
	set( "value",({ 570,"silver" }) );
}
