#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Silvery Scute","��ɫ�ۼ�" );
	add( "id", ({ "scute" }) );
	set_short( "��ɫ�ۼ�" );
	set_long(@LONG
	һ����ҫ����ɫ��â���ۼס�
LONG
           );
	set( "unit","��" );
	set( "weight",100 );
	set( "type","body" );
	set( "material","light_metal" );
	set( "armor_class",23 );
	set( "defense_bonus",2 );
	set( "value",({ 800,"silver" }) );
}
