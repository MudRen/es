// A list for magic level, by Yueh 1995/3/11
#include <mudlib.h>

inherit OBJECT;

void create()
{
        seteuid(getuid());
        set_name( "list", "���а�" );
        set_short( "ħ���ȼ����а�" );
        set_long( (string)find_object_or_load("/d/mage/tower/obj/topmages")->get_list(1));
        set( "unit", "��" );
        set( "weight", 5 );
        set( "value", ({ 20, "silver" }) );
        set( "useless", 1 );
}
