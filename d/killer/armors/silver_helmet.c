#include <mudlib.h>

inherit ARMOR;

string C_NAME="��ϼ�ͷ��";

void create()
{
	set_name( "silver helmet", C_NAME );
	add( "id", ({ "helmet" }) );
	set_short( C_NAME );
	set_long(
		"һ����������ɫͷ�����ⶥͷ����ŵ���������ҵ���Լ�������\n"
		"�����ľ��Ľ��������������Ժ���������˵�����ⶥͷ���ķ���\n"
		"�����˸���ħ�����⣬�Ѿ��޷��ٸ�ǿ�ˡ�\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "material", "knight" );
	set( "armor_class", 10 );
	set( "extra_skills", ([ "tactic":10 ]) );
	set( "weight", 70 );
	set( "value", ({ 250, "gold" }) );
	set( "no_sale", 1);
}
