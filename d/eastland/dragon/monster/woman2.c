#include "../../layuter.h"

inherit MONSTER;

void create()
{
        object boots,dagger,shield,legging,plate,cloak;

        ::create();
        set_level(1);
        set_name( "Six Poul", "六婆" );
        add ("id", ({ "draconian", "woman","poul" }) );
        set_short( "六婆");
        set("unit","位");
        set("alignment",-100);
        set("weight",400);
        set("wealth/silver",10);
        set_long(
           "六婆是龙人族中有名的长舌妇，城里大大小小的闲事你问她准没错。\n"
        );
        set_perm_stat("int", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("kar",2);
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        set_c_verbs(({"%s用她的手掌打向%s", "%s用她的舌头向%s舔去"}));
        set("chat_chance",10);
        set("chat_output",({
          "六婆说：阿牛听说要娶老婆了。\n",
          "六婆说：听说祭师藏有一个重要的卷轴。\n",
          "六婆说：龙人战士们最近听说要出征了。\n",
          "六婆说：听说要找到那棵树，要有耐心且仔细的寻找。\n"
          }));
}
