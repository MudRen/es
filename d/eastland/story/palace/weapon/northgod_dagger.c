#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("Crystal dagger","ˮ��ذ��");
        add ("id", ({"dagger" }) );
        set_short("ˮ��ذ��");
        set_long(@LONG
һ��ˮ���Ƴɵ�ذ�ף�ͨ�徧Ө͸����΢΢�����׹⡣
LONG);
        set("type", "dagger");
        set("unit","��");
        set("weapon_class",25);
        set("min_damage", 14 );
        set("max_damage", 28);
        set("weight", 50);
        set("value", ({ 2000, "silver" }) );
}
