#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "blue battle armor", "����ս��" );
	add( "id", ({ "battle armor", "armor" }) );
	set_short( "����ս��" );
	set_long(@C_LONG
����һ���ɽ���Ƶ�ս�ף���᰹�����������ʽ���׷�Ϊ�ࡢ�졢��
�������֣��ֱ𷢸�����Ʒ������١�
C_LONG
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "weight", 240 );
	set( "armor_class", 24 );
	set( "defense_bonus", 4 );
	set( "value", ({ 1500, "silver" }) );
}
