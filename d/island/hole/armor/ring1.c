#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Protect Ring","�ӻ���ָ" );
	add( "id", ({ "ring" }) );
	set_short( "�ӻ���ָ" );
	set_long(@LONG
	�ú���ʹ֮����ͬ�������ɵĽ�ָ����ʥ����
	�¿ɵõ���ʹ�ı�����
LONG
		 );
	set( "unit","ֻ" );
	set( "type","finger" );
	set( "material","element" );
	set( "weight",5 );
	set( "value",({ 1750,"silver" }) );
	set( "defense_bonus",6 );
	set( "special_defense",([ "evil":20 ]) );
}
