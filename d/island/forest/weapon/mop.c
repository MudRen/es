#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Mop","�ϰ�");
    set_short("�ϰ�");
    set_long(@LONG
���ǰ��ϰѣ�������ɣ�ֻ�������ϵأ�
LONG
            );
     set("unit","��");
     set("type","longblade");
     set("weapon_class",5);
     set("min_damage",5);
     set("max_damage",8);
     set("weight",50);
     set("value",({10,"silver"}) );
}