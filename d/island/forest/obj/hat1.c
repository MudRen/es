#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Dark Cap","���ƹ�");
    add("id",({"hat","cap"}) );
    set_short("���ƹ�");
    set_long(@LONG
���Ǽ������޹��ñ�ӣ����µ���ɫ�ݷ���Ҫ��������һ�㡣
LONG
            );
    set("unit","��");
    set("type","head");
    set("material","wood");
    set("armor_class",6);
    set("defense_bonus",1);
    set("weight",100);
    set("value",({550,"silver"}) );
}
