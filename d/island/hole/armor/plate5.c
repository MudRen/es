#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Earth Plate","�������" );
	add( "id", ({ "plate" }) );
	set_short( "�������" );
	set_long(@LONG
	�ɴ��֮ĸ�������������ף���˵ֻҪ��ش�
	�ڣ��Ͳ������𺦡�
LONG
	);
	set( "unit","��" );
	set( "weight",120 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",36 );
	set( "defense_bonus",3 );
	set( "value",({ 6400,"silver" }) );
}
