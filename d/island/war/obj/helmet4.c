#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Silvery Visor","��ɫ����" );
	add( "id", ({ "visor" }) );
	set_short( "��ɫ����" );
	set_long(@LONG
	һ����ҫ����ɫ��â�����֡�
LONG
           );
	set( "unit","��" );
	set( "weight",50 );
	set( "type","head" );
	set( "material","light_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",0 );
	set( "value",({ 790,"silver" }) );
}
