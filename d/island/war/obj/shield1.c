#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Bronze Shield","��ͭ��" );
	add( "id", ({ "shield" }) );
	set_short( "��ͭ��" );
	set_long(@LONG
	����һ������ͭ����Ķܣ��ڶܵı�Ե������
	һЩ����ʯ�������͵Ķ�����������ʿ�ı�׼
	�䱸��
LONG
           );
	set( "unit","��" );
	set( "weight",150 );
	set( "type","shield" );
	set( "material","knight" );
	set( "armor_class",8 );
	set( "defense_bonus",4 );
	set( "value",({ 1260,"silver" }) );
}
