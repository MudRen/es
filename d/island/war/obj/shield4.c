#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Shield","�׽��" );
	add( "id", ({ "shield" }) );
	set_short( "�׽��" );
	set_long(@LONG
	�����ð׽����Ķܡ�
LONG
           );
	set( "unit","��" );
	set( "weight",100 );
	set( "type","shield" );
	set( "material","knight" );
	set( "armor_class",7 );
	set( "defense_bonus",5 );
	set( "special_defense",([ "fire":30,"cold":-15 ]) );
	set( "value",({ 2710,"silver" }) );
}
