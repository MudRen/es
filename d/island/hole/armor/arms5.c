#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fire Scale Arms","���뻤��" );
	add( "id",({ "arms" }) );
	set_short( "���뻤��" );
	set_long(@LONG
	����һ�Աۻ���ÿ���ۻ��϶�����һƬ������
	����Ƭ��
LONG
           );
	set( "unit","˫" );
	set( "weight",50 );
	set( "type","arms" );
	set( "material","leather" );
	set( "armor_class",5 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":25 ]) );
	set( "value",({ 570,"silver" }) );
//	set( "no_sale",1 );
}
