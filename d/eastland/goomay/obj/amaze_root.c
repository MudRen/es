#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("amaze root","���컨�ĸ�");
        add( "id" , ({ "root" }) );
        set_short("���컨�ĸ�");
        set_long("����һ�κںڵġ������۵�������\n");
        set("unit","��");
        set("weight", 10);
        set("value", ({20, "silver"}) );
}
