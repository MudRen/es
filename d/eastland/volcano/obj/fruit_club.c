#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "fruit_club", "С���" );
	set_short( "С���" );
	set_long(
		"����ר���������˲ι��õ���ӡ�\n"
	);
	set( "no_sale", 1 );
	set( "unit", "ֻ" );
	set( "weight", 5 );
	set( "value", ({ 1, "silver" }) );
}
