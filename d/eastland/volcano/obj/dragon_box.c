#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "dragon_box", "�����ĺ���" );
	set_short(  "�����ĺ���" );
        add ( "id" , ({"box"}) );
	set_long(
	  "��������춺����ĺ��ӣ���˵����ǿ������������Ի�����ء�\n"
	);
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "weight", 10 );
	set( "value", ({ 1, "gold" }) );
}
