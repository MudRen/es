#include <mudlib.h>

inherit WEAPON ;

void create()
{
	set_name("long sword", "����");
	add ("id", ({ "sword" }) );
	set_short( "a long sword", "����");
	set_long(
		"It has a steel blade which is very sharp.\n",
		"��ѳ�����ʮ�ַ����Ľ��档\n"
	);
	set( "weight", 40 );
	set( "weapon_class", 7 );
	set( "type", "shortblade" );
	set( "min_damage", 4 );
	set( "max_damage", 7 );
	set ("value", ({ 12, "gold" }) );
}
