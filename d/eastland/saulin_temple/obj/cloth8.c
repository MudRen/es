#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "short cloth", "�ƶ̹�" );
	add("id",({"cloth"}) ); 
          set_short( "�ƶ̹�" );
	set_long(
"����һ��һ���η����д����·���ν֮�̹ң����е����ˡ�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "armor_class", 10 );
        set("material","cloth");
	set( "defense_bonus", 2 );
	set( "weight", 50 );
	set( "value", ({ 290, "silver" }) );
}
