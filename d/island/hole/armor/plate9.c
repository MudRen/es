#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Blood Plate","����Ѫ��" );
	add( "id", ({ "plate" }) );
	set_short( "����Ѫ��" );
	set_long(@LONG
	Ϊ�˵õ��ڰ��ļӻ����ú�ѪȾ�ɵ����ף���
	ս���ϵĲ�����֮һ��
LONG
           );
	set( "unit","��" );
	set( "weight",110 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",38 );
	set( "defense_bonus",3 );
	set( "value",({ 2250,"silver" }) );
}
