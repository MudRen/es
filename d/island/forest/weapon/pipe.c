#include "../tsunami.h"

inherit WEAPON;

void create()
{
    set_name("Pipe","�̶�");
    set_short("�̶�");
    set_long(@LONG
������ϸ�����ɵ��̶���ǰͷ�����˸�СС���̲ݴ���
LONG
            );
    set("unit","��");
    set("type","dagger");
    set("weapon_class",4);
    set("min_damage",3);
    set("max_damage",6);
    set("weight",50);
    set("value",({20,"silver"}) );
}