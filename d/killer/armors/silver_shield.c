
#include <mudlib.h>

inherit ARMOR;

string C_NAME="��ϼ��";

void create()
{
	set_name( "silver shield", C_NAME );
	add( "id", ({ "shield" }) );
	set_short( C_NAME );
	set_long(
		"һ����������ɫ���ƣ����������ŵ���������ҵ���Լ�������\n"
		"�����ľ��Ľ��������������Ժ���������˵����������Ƶķ���\n"
		"�����˸���ħ�����⣬�Ѿ��޷��ٸ�ǿ�ˡ�\n"
	);
	set( "unit", "��" );
	set( "type", "shield" );
	set( "material" ,"knight");
	set( "armor_class", 10 );
	set( "extra_skills", ([ "block":10 ]) );
	set( "weight", 100 );
	set( "value", ({ 270, "gold" }) );
	set( "no_sale", 1);
}
