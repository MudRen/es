#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Dark Robe","������");
    add("id",({"robe"}) );
    set_short("������");
    set_long(@LONG
���Ǽ������ۣ�������������������ɫ���ݷ�Ҫ��������һ�㡣
LONG
            );
    set("unit","��");
    set("type","body");
    set("material","wood");
    set("armor_class",23);
    set("defense_bonus",2);
    set("weight",150);
    set("value",({900,"silver"}) );
}
