#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("Westgod's fork","@@query_short");
        add ("id", ({"fork" }) );
        set_short("@@query_short");
        set_long(@LONG
一柄纯金打造的的武器，前端有三个大叉，既尖又利。  
LONG);
        set("type", "thrusting");
        set("unit","柄");
        set("weapon_class",30);
        set("min_damage", 18 );
        set("max_damage", 35);
        set("weight", 80);
        set("value", ({ 1500, "silver" }) );
}
string query_short()
{
       return set_color("三叉□","HIY");
}