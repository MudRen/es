#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Pracrice pants","�����ȹ");
    add("id",({"skirt","pants"}) );
    set_short("�����ȹ");
    set_long(@LONG
����һ��������ȹ����һ��ϰ��֮ʿϰ��ʱ����֮װ����
LONG
            );
    set("unit","��");
    set("type","legs");
    set("material","cloth");
    set("armor_class",2);
    set("defense_bonus",0);
    set("weight",50);
    set("value",({20,"silver"}) );
}
    