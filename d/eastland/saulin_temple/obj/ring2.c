#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name("king-kong ring","���ָ��");
        add("id",({"ring"}) );
	set_short("���ָ��");
	set_long(
"�����ɽ�ս�--������ղ��ڶ��������ʹ�ù���ָ��,���зǷ��ķ�����\n"
);
	set( "unit", "��" );
	set( "weight", 10 );
	set("material","element");
	set( "type", "finger" );
	set("armor_class",0);
	set( "defense_bonus", 8 );
	set( "value", ({ 250, "gold" }) );
}
