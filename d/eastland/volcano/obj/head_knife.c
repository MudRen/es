#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "sharp knife", "����С��" );
	set_short( "����С��" );
	set_long(
		"����һ��ר��������ͷ­��С����\n"
	);
        add("id", ({"knife"}));
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "weight", 3 );
	set( "value", ({ 0, "silver" }) );
}
