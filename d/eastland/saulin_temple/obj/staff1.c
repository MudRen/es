#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "we-tow staff", "Τ����");
        add ("id",({ "staff"}) );
        set_short("Τ����");
        set("unit", "��");
        set_long(@C_LONG
����һ����ǧ����̴ľ���ɵ����ȣ�����ĵ�ʮ�ֵľ�ϸ����һ����֪��
��һ����ĳ��ʦ��������ľ�������ɵġ�ͬʱ��Ҳ�������·��ɵ����
C_LONG
        );
        set("weapon_class", 30);
        set("type", "bo");
        set("min_damage", 20);
        set("max_damage", 40);
        set("weight", 220 );
        set("no_sale",1);
        set("value", ({ 2500, "silver" }) );
}
