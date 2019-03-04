
#include <mudlib.h>

inherit MONSTER ;

void create()
{
        ::create();
        set_level(1);
        set_name("dog" ,"狗");
        add( "id", ({ "dog" }) );
        set_short( "野狗");
        set_long(
                "这是一只野狗, 你最好不要随便靠近它。\n"
        );
   set( "race", "beast" );
        set("unit", "只");
        set_perm_stat("str", 3);
        set_perm_stat("con", 2);
        set_perm_stat("dex", 3);
        set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set_c_limbs( ({ "後腿", "前脚", "头部", "尾巴", "身体" }) );
}
