#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Oath Cloak","��������" );
	add( "id",({ "cloak" }) );
	set_short( "��������" );
	set_long(@LONG
	���ĳ�Ϊʥ��ʱ����Ϊ������������
LONG
           );
	set( "unit","Ϯ" );
	set( "weight",40 );
	set( "type","cloak" );
	set( "material","cloth" );
	set( "armor_class",6 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "evil":20 ]) );
	set( "value",({ 1170,"silver" }) );
}
