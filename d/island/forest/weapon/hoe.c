#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("hoe","��ͷ");
    add("id",({"spade"}) );
    set_short("��ͷ");
    set_long(@C_LONG
����һ�ѳ�ͷ��
C_LONG
             );
    set("unit","��");
    set("type","longblade");
    set("weapon_class",5);
    set("min_damage",5);
    set("max_damage",10);
    set("weight",100);
    set("value",({20,"silver"}) );
 }

