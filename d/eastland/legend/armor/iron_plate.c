#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "silver_dragon vest", "����ս��" );
	add( "id", ({ "vest", "plate" }) );
	set_short( "����ս��" );
	set_long(@LONG
���ί�ж�����½������ʦ������æұ�������置���õ���һ�������󣬶�����
��������������������������Ƿ��Ļ��ߣ����Ὣʣ�ŵ������Ƴ�һƬƬ����Ƭ��
Ƕ�������һ���Ҵ���������֮�У����Ƴɵ�ս�ף��г�����ʥ�ķ�������������
�����ء�
LONG	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 35 );
	set( "defense_bonus", 1 );
	set( "weight", 270 );
	set( "value", ({ 2500, "silver" }) );
}
