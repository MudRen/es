#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Combat Cap","ս����");
    add("id",({"hat","cap"}) );
    set_short("ս����");
    set_long(@LONG
����һ�����ɾ��µ�ñ�ӡ�
LONG
            );
    set("unit","��");
    set("type","head");
    set("material","wood");
    set("armor_class",5);
    set("defense_bonus",2);
    set("weight",100);
    set("value",({300,"silver"}) );
}
