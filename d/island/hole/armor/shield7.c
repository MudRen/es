#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fire Scale Shield","�����" );
	add( "id", ({ "shield" }) );
	set_short( "�����" );
	set_long(@LONG
	����һ���ò��ʽ���Ľ�������Ķܣ�����һ
	��������Ƭ���������Ƭ��
LONG
           );
	set( "unit","��" );
	set( "weight",100 );
	set( "type","shield" );
	set( "material","heavy_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",3 );
	set( "special_defense",([ "fire":30,"cold":10 ]) );
	set( "value",({ 1440,"silver" }) );
//	set( "no_sale",1 );
}
