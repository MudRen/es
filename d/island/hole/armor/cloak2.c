#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Death Cloak","��������" );
	add( "id",({ "cloak" }) );
	set_short( "��������" );
	set_long(@LONG
	���Ǵ�˵�л�Ϩ��������������磬ֻ������
	����ӵ������
LONG
           );
	set( "unit","��" );
	set( "weight",40 );
	set( "type","cloak" );
	set( "material","cloth" );
	set( "armor_class",5 );
	set( "defense_bonus",6 );
	set( "special_defense",([ "fire":25,"cold":10,"none":15 ]) );
	set( "value",({ 975,"silver" }) );
}
