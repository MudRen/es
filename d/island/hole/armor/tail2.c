#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Fish Scale Tail","����β��" );
	add( "id", ({ "tail" }) );
	set_short( "����β��" );
	set_long(@LONG
	һ���õ��¶�Ѩˮ�׵ĺ�������Ƭ��ϲ�˿��
	�ɵ�β�ף���һ������Ƶ�β������ˡ�
LONG
           );
	set( "unit","��" );
	set( "weight",50 );
	set( "type","tail" );
	set( "material","cloth" );
	set( "armor_class",8 );
	set( "defense_bonus",2 );
	set( "value",({ 680,"silver" }) );
}
