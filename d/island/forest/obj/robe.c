#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Holy Robe","ʥ����");
    add("id",({"robe"}) );
    set_short("ʥ����");
    set_long(@LONG
����һ������ħ���ķ��ۣ�ֻ������������ݷ���ӵ��ȡ֮���ߡ���֮������ǿ����Դ
�Ƶġ�
LONG
            );
    set("unit","��");
    set("type","body");
    set("material","wood");
    set("armor_class",25);
    set("defense_bonus",2);
    set("weight",200);
    set("value",({700,"silver"}) );
}
