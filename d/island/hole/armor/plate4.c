#include <../hole.h>

inherit ARMOR;
void create()
{
	set_name( "Black Chainmail","��ɫ����" );
	add( "id", ({ "chainmail","mail" }) );
	set_short( "��ɫ����" );
	set_long(@LONG
	����Ĩ�ڵ�һ�����ף��������������������
LONG
           );
	set( "unit","��" );
	set( "weight",100 );
	set( "type","body" );
	set( "material","light_metal" );
	set( "armor_class",20 );
	set( "defense_bonus",2 );
	set( "value",({ 1440,"silver" }) );
}
