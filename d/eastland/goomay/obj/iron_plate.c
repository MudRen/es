
#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("red steel plate","������");
        add("id",({"plate","platemail"}) );
         set_short( "a red steel plate","������");
        set_long(
"This is a suit of plate make by red steel ,which can  \n"
"protect your body against opponent's attacks.\n",
"����һ���ɺ�ɫħ�������������ɵ����ף�ͨ�巺�����صĹ�â��\n"
        );
        set( "unit", "��" );
        set( "weight", 400 );
        set( "type", "body" );
        set( "armor_class", 30 );
        set( "defense_bonus", 3 );
	set( "material", "heavy_metal" );
        set( "value", ({ 680, "gold" }) );
}
