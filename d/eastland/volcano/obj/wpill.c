#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "living pill", "����ҩ��" );
	set_short( "����ҩ��" );
        add ( "id" , ({"pill"}) );
	set_long(
	  "����һ������ҩ�裬����ǧ������ҩ�����ɣ���˵������������\n"
	);
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "weight", 2 );
	set( "value", ({ 1, "gold" }) );
}
