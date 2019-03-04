#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("holy ring","��Ⱦ������ָ");
    add("id",({"ring"}) );
    set_short( "a holy ring","��Ⱦ������ָ");
	set_long(
		"This is a ring blessed by God.\n"
		"�����������֮һ �� ��Ⱦ����ʹ�ù��Ľ�ָ,�����������\n"
		"����֮ʿ, ����������֮���ӻ���ġ�\n" 
	);
	set( "unit", "��" );
	set( "weight", 12 );
	set( "type", "finger" );
    set( "material","monk");
	set( "armor_class", 0 );
	set( "defense_bonus", 9 );
	set( "value", ({ 300, "gold" }) );
	set( "no_sale", 1 );
}
