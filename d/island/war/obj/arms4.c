#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Armbands","�׽𻤱�" );
	add( "id", ({ "arm","armband" }) );
	set_short( "�׽𻤱�" );
	set_long(@LONG
	һ���ð׽����Ļ��ۡ�
LONG
           );
	set( "unit","��" );
	set( "weight",9 );
	set( "type","arms" );
	set( "material","knight" );
	set( "armor_class",3 );
	set( "defense_bonus",2 );
	set( "value",({ 1175,"silver" }) );
}
