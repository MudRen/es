#include <mudlib.h>
inherit ARMOR;

void create()
{
        set_name( "Thunder Vest", "雷电战甲");
        add( "id", ({ "thunder","vest" }) );
        set_short("Thunder Vest", "雷电战甲");
        set_long(@AAA
这是一件附有雷电精灵力量的铠甲，是妮作战时所穿的防具，铠甲
前面还刻有一个风精灵法印！　
AAA
        );
        set( "unit", "件"); 
        set( "type", "body" );
        set( "armor_class", 37 );
        set( "defense_bonus", 6 );
        set("material","element");
        set("special_defense",(["eletric":10]));
        set( "weight", 110 );
        set( "value", ({ 1700, "silver" }) );
}
