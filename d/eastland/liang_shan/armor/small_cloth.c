#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("general cloth","����");
    add("id",({"cloth"}) );
    set_short( "general cloth","����");
	set_long(
		"This is a suit of cloth \n",
		"����һ���ǳ��ǳ���ͨ���·�����·����㶼���ĵ���\n"
		
	);
	set( "unit", "��" );
	set( "weight", 50 );
	set( "type", "body" );
	set( "armor_class", 12 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "value", ({ 20, "gold" }) );
}
