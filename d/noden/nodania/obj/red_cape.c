#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "red cape", "������" );
	add( "id", ({ "cape" }) );
	set_short( "��ɫ����" );
	set_long(@CLONG
һ���ö�����˿���ķ��Ƶĺ�ɫ���磬��������Ү�������ҵı�־:
ʨ���ޡ�������翴�����������󣬶����ʵ�ϸ�ܣ���������һ��Ҳ��
������ж���
CLONG
	);
	set( "unit", "��" );
	set( "weight", 50 );
	set( "type", "cloak" );
	set( "material", "knight" );
	set( "armor_class", 10 );
	set( "defense_bonus", 8 );
	set( "special_defense", ([ "energy":10, "mental":-10 ]) );
	set( "no_sale",1 );
	set( "value", ({ 310, "gold" }) );
}
