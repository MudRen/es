#include "../tsunami.h"

inherit OBJECT;

void create()
{
    set_name("Radish","�ܲ�");
    set_short("�ܲ�");
    set_long(@LONG
��ֻ��һ��ĺ�ɫԲ��С�ܲ�!
LONG
            );
    set("unit","ֻ");
    set("weight",50);
    set("value",({0,"silver"}) );
    set("give_me_radish",1);
 }

