#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "alloyed platemail", "�Ͻ����" );
	add( "id", ({ "plate", "platemail", "mail" }) );
	set_short( "a suit of alloyed playemail", "�Ͻ����" );
	set_long(
		"You see a suit of alloyed platemail. It looks pretty heavy and\n"
		"can supply good protection.\n",
		"����һ����ĳ�ֲ�֪���Ͻ����Ŀ��ף��������൱�ء�\n"
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 25 );
	set( "weight", 300 );
	set( "value", ({ 1030, "silver" }) );
}
