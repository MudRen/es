#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("grey pallium","�Ҳ���");
    add("id",({"cloth","pallium"}) );
    set_short( "�Ҳ���");
	set_long(
		"����һ�������ܳ¾ɵİ������ģ��ûҲ�֯�Ͳ�������ɮ��ף������һ���Ϻõ����ġ�\n"
	);
	set( "unit", "��" );
	set( "weight", 150 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 9 );
	set( "value", ({ 800, "silver" }) );
}
