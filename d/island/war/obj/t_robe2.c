#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Combat Robe","ս������");
    add("id",({"robe"}) );
    set_short("ս������");
    set_long(@LONG
���Ǽ����ɾ��µķ��ۡ�
LONG
            );
    set("unit","��");
    set("type","body");
    set("material","wood");
    set("armor_class",21);
    set("defense_bonus",4);
    set("weight",80);
    set("value",({700,"silver"}) );
}
