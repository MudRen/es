#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "scroll", "����" );
	set_short( "ȾѪ�ľ���" );
	set_long(
		"/adm/daemons/npc_kills"->get_list(),
		"/adm/daemons/npc_kills"->get_list(1) );
	set( "unit", "��" );
	set( "weight", 5 );
	set( "value", ({ 5, "silver" }) );
	set( "useless", 1 );
}
