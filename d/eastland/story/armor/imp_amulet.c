#include "../story.h"
inherit ARMOR;
inherit SARM"OR";

void create()
{
        set_name("twelve-god amulet","十二天都符□");
        add( "id", ({ "amulet" }) );
        set_short( set_color("十二天都符□","HIC"));
        set_long(@C_LONG
一个划著梵语的护符。□符上面的字龙飞凤舞，笔力苍劲，令你看不懂写的是什麽
。
C_LONG
        );
        set("unit","个");
        set( "type", "misc" );
        set("material","cloth");
        set("the_one",1);
        set( "defense_bonus", 1 );
        set( "weight", 1 );
        set( "value", ({ 5050, "silver" }) );
}



