#include <mudlib.h>

inherit WEAPON;

void create()
{
    set_name(" Prick","��ħ׶");
    add("id",({ "dagger" }) );
    set_short("��ħ׶");
    set_long( @C_LONG
����ħ��ħ��ʿר�õ����������ɵ����ʹ����Ϊս���е�������
C_LONG
            );
    set("unit","��");
    set("weapon_class",17);
    set("type","dagger");
    set("min_damage",10);
    set("max_damage",19);
    set("weight",50);
    set("value", ({400,"silver"}) );
}
