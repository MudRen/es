#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Helmet","ս��ͷ��" );
	add( "id", ({ "helmet" }) );
	set_short( "ս��ͷ��" );
	set_long(@LONG
	��ͷ����ս�����׸պ���һ�ף�������һ����
	�Ͻ���Ľ������ɵģ���ȷʵ����ͷ����
LONG
           );
	set( "unit","��" );
	set( "weight",45 );
	set( "type","head" );
	set( "material","heavy_metal" );
	set( "armor_class",8 );
	set( "defense_bonus",2 );
	set( "value",({ 1500,"silver" }) );
//	set( "no_sale",1 );
}
