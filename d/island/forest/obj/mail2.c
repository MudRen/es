#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Sikoku chianmail","����Ѫ��");
    add("id",({"sikoku","chainmail","mail"}) );
    set_short("����Ѫ��");
    set_long(@C_LONG
Ϊ�˵õ��ڰ��ļӻ����ú�ѪȾ�ɵ����ף���ս���Ĳ�����֮һ��
C_LONG
    );

    set("unit","��");
    set("type","body");
    set("material","light_metal");
    set("weight",100);
    set("armor_class",20);
    set("defense_bonus",2);
    set("value",({500,"silver"}) );
}
