#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Police Uniform","���ý���װ");
    add("id",({"cloth","uniform"}) );
    set_short("���ý���װ");
    set_long(@LONG
����ħ�屣�������е�����ר���Ʒ�����һλ�����еı����ٴ�����ʱ������
���������Ĵ��ڣ�ͬʱҲ�ܸ���ʹ�����൱�̶ȵķ������������참����Ч�ʣ�
LONG
            );
     set("unit","��");
     set("type","body");
     set("material","cloth");
     set("armor_class",30);
     set("defense_bonus",2);
     set("special_defense",(["divine":20,"mental":15,"fire":-15]) );
     set("weight",150);
     set("value",({600,"silver"}) );
}              