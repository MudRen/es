
#include "../../layuter.h"

inherit MONSTER ;

void create ()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(1);
        set_name( "aunt cheng", "张大婶" );
        add ("id", ({ "draconian", "cheng","aunt" }) );
        set_short( "张大婶");
        set("unit","位");
        set("alignment",-100);
        set("weight",400);
        set("wealth/silver",10);
        set_long(
           "张大婶最喜欢道人长短，而且喜欢散布谣言。\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        set_c_verbs(({"%s用她的手掌打向%s,%s用她的舌头向%s舔去"}));
        set("chat_chance",5);
        set("chat_output",({
          "张大婶说：阿牛听说要取老婆了。\n",
          "张大婶说：乌家的小儿子听说是白痴。\n",
          "张大婶说： 听说小龙女生了一个女娃。\n",
          "张大婶说：听说郑大户藏有一瓶陈年好酒。\n",
          "张大婶说：听说龙人工匠是一个不出世的奇人，任何物品他都造的出来。\n" 
          }));
}
