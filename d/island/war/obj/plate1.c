#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Bronze Plate","��ͭ����" );
	add( "id", ({ "plate" }) );
	set_short( "��ͭ����" );
	set_long(@LONG
	����һ������ͭƬ��ɵ�ս�ף���Ȼ��΢����
	һЩ���������Ǳ����ĺö���ม�
LONG
           );
	set( "unit","��" );
	set( "weight",220 );
	set( "type","body" );
	set( "material","heavy_metal" );
	set( "armor_class",30 );
	set( "defense_bonus",3 );
	set( "value",({ 1440,"silver" }) );
}
