#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fish Scale Scute","���ۼ�" );
	add( "id", ({ "scute" }) );
	set_short( "���ۼ�" );
	set_long(@LONG
	һ���������˶�Ѩˮ�׵ĺ�������Ƭ����Ͳ�
	˿��֯�ɵ��·���
LONG
           );
	set( "unit","��" );
	set( "weight",110 );
	set( "type","body" );
	set( "material","cloth" );
	set( "armor_class",20 );
	set( "defense_bonus",4 );
	set( "value",({ 870,"silver" }) );
}
