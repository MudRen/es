#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Acton","�׽����Ӽ�" );
	add( "id", ({ "acton" }) );
	set_short( "�׽����Ӽ�" );
	set_long(@LONG
	һ���ð׽��������Ӽס�
LONG
           );
	set( "unit","��" );
	set( "weight",100 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",35 );
	set( "defense_bonus",2 );
	set( "value",({ 2670,"silver" }) );
}
