#include "takeda.h"

inherit ARMOR;

void create()
{
    set_name("black cloth","��ֱ׺");
    add("id",({"cloth"}) );
    set_short( "black cloth","��ֱ׺");
	set_long(
		"This is a black cloth \n",
		"����һ��ʽ���򵥵ĺ��£�ͨ������С��������ڴ���\n"
		
	);
	set( "unit", "��" );
	set( "weight", 60 );
	set( "type", "body" );
	set( "armor_class", 15 );
        set("material","cloth");
	set( "defense_bonus", 3 );
	set( "value", ({ 33, "gold" }) );
}
