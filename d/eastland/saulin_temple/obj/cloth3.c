#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "wen-su robe", "�������" );
	add( "id", ({ "robe" }) );
	set_short( "�������" );
	set_long(
		"�����Ǽ������ʱ�������·�����������Ǽ�����������ʱ���ĳ��ۡ�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "armor_class", 20 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "weight", 100 );
	set( "value", ({ 987, "silver" }) );
}
