#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Silver Cloak","��˿����" );
	add( "id",({ "cloak" }) );
	set_short( "��˿����" );
	set_long(@LONG
	��˵������ʿ����������Ħ�����硣
LONG
           );
	set( "unit","��" );
	set( "weight",40 );
	set( "type","cloak" );
	set( "material","knight" );
	set( "armor_class",6 );
	set( "defense_bonus",4 );
	set( "special_defense",([ "fire":30,"cold":-10,"none":15 ]) );
	set( "value",({ 1170,"silver" }) );
}
