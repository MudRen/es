#include <mudlib.h>

inherit ARMOR;

string C_NAME="���˿����";

void create()
{
	set_name( "silver gauntlets", C_NAME );
	add( "id", ({ "gauntlets" }) );
	set_short( C_NAME );
	set_long(
		"һ˫��������ɫ���ף���˫������ŵ���������ҵ���Լ�������\n"
		"�����ľ��Ľ��������������Ժ���������˵������˫���׵ķ���\n"
		"�����˸���ħ�����⣬�Ѿ��޷��ٸ�ǿ�ˡ�\n"
	);
	set( "unit", "˫" );
	set( "type", "hands" );
	set( "material", "knight" );
	set( "armor_class", 5 );
	set( "extra_skills", ([ "parry" :10 ]) );
	set( "weight", 80 );
	set( "value", ({ 210, "gold" }) );
	set( "no_sale", 1);
}
