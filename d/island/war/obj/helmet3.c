#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Visor","�׽�����" );
	add( "id", ({ "visor" }) );
	set_short( "�׽�����" );
	set_long(@LONG
	һ���ð׽��������֡�
LONG
           );
	set( "unit","��" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","knight" );
	set( "armor_class",6 );
	set( "defense_bonus",2 );
	set( "value",({ 1370,"silver" }) );
}
