#include <mudlib.h>
inherit WEAPON;

void create()
{
    set_name("Regular spear","��ʽ��ì");
    add("id",({"spear"}) );
    set_short("��ʽ��ì");
    set_long(@LONG
����һ��ħ���ͨ�õĳ�ì��
LONG
            );
    set("unit","��");
    set("type","thrusting");
    set("weapon_class",15);
    set("min_damage",10);
    set("max_damage",18);
    set("weight",150);
    set("value",({150,"silver"}) );                
}