#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("Westgod's fork","@@query_short");
        add ("id", ({"fork" }) );
        set_short("@@query_short");
        set_long(@LONG
һ���������ĵ�������ǰ����������棬�ȼ�������  
LONG);
        set("type", "thrusting");
        set("unit","��");
        set("weapon_class",30);
        set("min_damage", 18 );
        set("max_damage", 35);
        set("weight", 80);
        set("value", ({ 1500, "silver" }) );
}
string query_short()
{
       return set_color("�����","HIY");
}