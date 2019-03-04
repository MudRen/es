#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "king-kong staff", "金刚杖");
        add ("id",({ "staff"}) );
        set_short( "king-kong staff", "金刚杖");
        set("unit", "把");
        set_long(
            "",@C_LONG
这把金刚杖外表黝黑没有光泽，还发出一股逼人的寒气，看起来十分沈重，
据说是由千年玄铁铸造而成。
C_LONG
        );
        set( "weapon_class", 45);
        set( "type", "bo");
        set( "min_damage", 25);
        set( "max_damage", 47);
        set( "no_sale", 1);
        set( "weight",180 );
        set( "value", ({ 3800, "silver" }) );
}
