#include <mudlib.h>

inherit ARMOR;

string C_NAME="[37;1m������[37;0m";

void create()
{
	set_name( "silver platemail", C_NAME );
	add( "id", ({ "plate", "platemail" }) );
	set_short( C_NAME );
	set_long(
		"һ����������ɫ���ף����׿�����ŵ���������ҵ���Լ�������\n"
		"�����ľ��Ľ��������������Ժ���������˵�������׿��׵ķ���\n"
		"�����˸���ħ�����⣬�Ѿ��޷��ٸ�ǿ�ˡ�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "knight");
	set( "armor_class", 40 );
	set( "weight", 370 );
	set( "value", ({ 330, "gold" }) );
	set( "no_sale",1 );
}
