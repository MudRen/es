#include "../saulin_temple.h"

inherit ARMOR;

void create()
{
    set_name("tiger ring","����ָ��");
    add("id",({"ring"}) );
    set_short("����ָ��");
	set_long(
		"���Ƿ����޺���ʹ�õ�ָ��,�����ṩ�㲻��ķ�����\n"
	);
	set( "unit", "��" );
	set( "weight", 19 );
        set("material","leather");
	set( "type", "finger" );
	set( "armor_class", 0 );
	set( "defense_bonus", 6 );
	set( "value", ({ 2000, "silver" }) );
}
