#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Platinum Amulet","�׽����" );
	add( "id", ({ "amulet" }) );
	set_short( "�׽����" );
	set_long(@LONG
	�Ŵ��׼��Ļ���֮һ�����������������ı���
	�������Ծ��и߹�ļ�ֵ��
LONG
           );
	set( "unit","ö" );
	set( "weight",5 );
	set( "type","misc" );
	set( "material","element" );
	set( "defense_bonus",4 );
	set( "value",({ 2620,"silver" }) );
}
