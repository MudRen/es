#include <mudlib.h>

inherit ARMOR;

string C_NAME="���˿�ּ�";

void create()
{
	set_name( "silver leggings", C_NAME );
	add( "id", ({ "leggings" }) );
	set_short( C_NAME );
	set_long(
		"һ����������ɫ�ּף��⸱�ּ���ŵ���������ҵ���Լ�������\n"
		"�����ľ��Ľ��������������Ժ���������˵���������ּ׵ķ���\n"
		"�����˸���ħ�����⣬�Ѿ��޷��ٸ�ǿ�ˡ�\n"
	);
	set( "unit", "��" );
	set( "type", "legs" );
	set( "material", "knight");
	set( "armor_class", 10);
	set( "weight", 150 );
	set( "value", ({ 270, "gold" }) );
	set( "no_sale", 1);
}
