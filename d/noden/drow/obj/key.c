#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name( "iron key","����Կ��");
        add( "id", ({ "key" }) );
        set_short( "iron key", "����Կ��");
        set_long(            
                "����һ�ѿ������ش����ŵ�Կ�ס�\n"
        );
        set( "unit", "��" );
        set( "to_lock", "IRON_DOOR" );
        set( "weight", 5 );
        set( "value", ({ 30, "silver" }) );
        set( "no_sale", 1 );
}
