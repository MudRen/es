#include <mudlib.h>

inherit ARMOR;
void create()
{
	set_name( "Bronz Bracer","��ͭ����" );
	add( "id",({ "bracer" }) );
	set_short( "��ͭ����" );
	set_long(@LONG
	����һ������ͭ����Ļ��󣬿���ȷ������ս
	���в�����Ϊ�������˶�ɥʧս������
LONG
           );
	set( "unit","��" );
	set( "weight",50 );
	set( "type","hands" );
	set( "material","heavy_metal" );
	set( "armor_class",4 );
	set( "defense_bonus",2 );
	set( "value",({ 450,"silver" }) );
}
