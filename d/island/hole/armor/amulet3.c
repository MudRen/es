#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Dragon bone","����" );
	add( "id", ({ "bone" }) );
	set_short( "����" );
	set_long(@LONG
	��˵������������Ҫ��һ���ͷ������ʥ����
	������
LONG
           );
	set( "unit","��" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",6 );
	set( "special_defense",([ "fire":10 ]) );
	set( "value",({ 2620,"silver" }) );
}
