#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Wolf Blade","����");
    add("id",({"blade","sword"}) );
    set_short("����");
    set_long(@LONG
����ħ��������µ���������֮һ���ഫħ�����ÿ��µĹ�ħ����������������
�붯���ں���һ���������ͬ��Ҳ����˵����ġ�
LONG
            );
    set("unit","��");
    set("type","longblade");
    set("weight",100);
    set("weapon_class",30);
    set("min_damage",20);
    set("max_damage",33);
    set("value",({700,"silver"}) );        
}      