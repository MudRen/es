#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("white jade ring","��֬����");
        add("id",({"ring"}) );
         set_short( "white jade ring","��֬����");
	set_long(
"This is a ring made of white jade . \n"
"������֬�������Ƴɵ�ָ��,���зǷ��ķ�����\n"
);
	set( "unit", "��" );
	set( "weight", 10 );
	set( "type", "finger" );
	set( "material","scholar");
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
	set( "value", ({ 150, "gold" }) );
}
