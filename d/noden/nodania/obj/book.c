#include "/u/e/ega/ega.h"
inherit OBJECT;
int             create()
{
        set_name("book", "ʥ��");
        set_short("ʥ��");
        set_long(@CLONG
����һ��ʥ����
CLONG
        );
        set("id", ({"book", "holy book"}));
        set("unit", "��");
        set( "weight", 0 );
        set ("value", ({ 1, "silver" }) );
        seteuid( getuid() );
}
