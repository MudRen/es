// A list for magic level, by Yueh 1995/3/11
#include <mudlib.h>

inherit OBJECT;

void create()
{
	seteuid(getuid());
        set_name( "list", "���а�" );
        set_short( "�����ȼ����а�" );
        set_long( (string)find_object_or_load("/d/scholar/scholar/topscholar2")->get_list());
        set( "unit", "��" );
        set( "weight", 2 );
        set( "value", ({ 1, "silver" }) );
        set( "useless", 1 );
}
