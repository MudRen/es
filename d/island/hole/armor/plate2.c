#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Plate","ս������" );
	add( "id", ({ "plate" }) );
	set_short( "ս������" );
	set_long(@LONG
	�����������ԹŴ����������ս�ס����ս��
	ֻ����������������ʸ񴩣���Ϊ�ܵ�������
	��������ˣ��ض��Ǹ�������ս����ʿ��
LONG
           );
	set( "unit","��" );
	set( "weight",130 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",36 );
	set( "defense_bonus",8 );
	set( "value",({ 1440,"silver" }) );
//	set( "no_sale",1 );
}
