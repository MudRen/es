#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Snow Gloves","ѩ����");
    add("id",({"gloves"}) );
    set_short("ѩ����");
    set_long(@C_LONG
ѩ���ް׻���Ƥë���ƳɵĻ��֣�������������ϰ����ݡ�
C_LONG
    );

    set("unit","˫");
    set("type","hands");
    set("material","light_metal");
    set("weight",30);
    set("armor_class",4);
    set("defense_bonus",1);
    set("value",({500,"silver"}) );
}
