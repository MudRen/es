#include "../echobomber.h"

inherit OBJECT;

void create()
{
	set_name( "blue pearl", "������" );
	add( "id", ({ "pearl" }) );
	set_short( " blue pearl", "������" );
	set_long(
		"The very expensive pearl,but you think nobody can understand its value\n",
		"�ǳ����������,����������û�������˽����ļ�ֵ\n"
	);
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "echo_pearl",1);
	set( "weight", 13 );
	set( "value", ({ 1, "silver" }) );
}
