#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Silvery Shield","��ɫ�̶�" );
	add( "id", ({ "shield" }) );
	set_short( "��ɫ�̶�" );
	set_long(@LONG
	һ����ҫ����ɫ��â�Ķܡ�
LONG
           );
	set( "unit","��" );
	set( "weight",120 );
	set( "type","shield" );
	set( "material","light_metal" );
	set( "armor_class",5 );
	set( "defense_bonus",2 );
	set( "special_defense",([ "fire":30,"cold":-15 ]) );
	set( "value",({ 1110,"silver" }) );
}
