// Echo/item/lamp.c
#include "../echobomber.h"
inherit OBJECT;
void create()
{
set_name("Lamp","�͵�");
set("c_short","һյ�͵�");
set("c_long",@Lamp
һյ�͵�,�ƺ��й����������
Lamp
);
set("id",({"lamp"}));
set( "unit", "յ");
set("weight", 1);
 set("value", ({ 5, "silver" }));
}
void init()
{
add_action("light_lamp","light");
}

int light_lamp(string str)
{
    if (!str||str!="lamp") return 0;
    
}
