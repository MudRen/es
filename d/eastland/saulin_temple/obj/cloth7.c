#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "short cloth", "�̹�" );
	add("id",({"cloth"}) ); 
          set_short( "�̹�" );
	set_long(
"����һ��һ���η����д����·�,ν֮�̹ҡ�\n"
	);
	set( "unit", "��" );
        set("material","cloth");
	set( "type", "body" );
	set( "armor_class", 10 );
	set( "defense_bonus", 3 );
	set( "weight", 70 );
	set( "value", ({ 470, "silver" }) );
}
