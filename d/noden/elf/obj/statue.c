#include "../layuter.h"
inherit ARMOR;

void create()
{
        set_name("statue", "MIYUKI����");
        add( "id", ({ "statue" }) );
        set_short( "MIYUKI����" );
        set_long(
                 "���ǰ���˹̫̫Miyuki�ĵ���\n"
        );
        set( "unit", "��");
        set( "weight", 50 );
        set( "value", ({ 0, "silver" }) );
        set("get_my_statue",1);
}
