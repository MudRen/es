#include "../dony.h"

inherit OBJECT;

void create()
{
        set_name("bear-snake pill","天山九转熊蛇丸");
        add( "id" , ({ "pill" }) );
        set_short( "天山九转熊蛇丸");
        set_long(@C_LONG
这是一颗白色的药丸,闻起来有点臭臭的。九转熊蛇丸是天山二老采集十头大黑熊
掌和三十条大蟒蛇胆以及千年人□研制而成的,其珍贵无比, 更兼有起死回生的疗
效。
C_LONG  );      
        set("unit","颗");
        set("weight",1);
        set("no_sale",1);
        set("value", ({1, "silver"}) );
}
