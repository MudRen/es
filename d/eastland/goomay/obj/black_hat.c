#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black hat", "����ñ" );
	add( "id", ({ "hat","cap" }) );
	set_short( "a black hat", "����ñ" );
	set_long(
		"You see policeman's black hat.\n",
		"����һ�������ǵ���ʽñ�ӣ����滹���˸���ë��\n"
	);
	set( "unit", "��" );
	set( "type", "head" );
        set("material","cloth");
	set( "weight", 60 );
	set( "armor_class", 3 );
	set( "value", ({ 120, "silver" }) );
}
