#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("Holy Hat","ʥ��ñ");
    add("id",({"hat","cap"}) );
    set_short("ʥ��ñ");
    set_long(@LONG
����һ������ħ����ñ�ӣ�ֻ������������ݷ���ӵ��ȡ֮���ߡ���֮������ǿ����Դ
�Ƶġ�
LONG
            );
    set("unit","��");
    set("type","head");
    set("material","wood");
    set("armor_class",6);
    set("defense_bonus",1);
    set("weight",100);
    set("value",({400,"silver"}) );
}
