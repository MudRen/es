#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black eye patch", "������" );
	add( "id", ({ "eye patch", "patch" }) );
   set_short( "������" );
	set_long(
		"һ���������ܻ����ĺ�ɫ���֣��⸱���ֵ�����һ������Ϊ��������������\n"
		"�������ܿᡣ\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
	set( "material","leather");
	set( "armor_class", 2 );
	set( "defense_bonus", 1 );
	set( "special_defense",(["electric":1,"clod":1]) );
	set( "value", ({ 250, "silver" }) );
	set( "weight", 15 );
}
