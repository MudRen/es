#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Cloth feet","��Ь");
    add("id",({"boots","boot","feet"}) );
    set_short("��Ь");
    set_long(@LONG
�����������Ҵ�ͳ�Ĳ�Ь�����ĳ����һ���������Щ���ƣ����ǿ���ֱ�ӵ�
��Ь�Ӵ���
LONG
            );
    set("unit","˫");
    set("type","feet");
    set("material","cloth");
    set("armor_class",3);
    set("defense_bonus",0);
    set("weight",50);
    set("value",({10,"silver"}) );
}