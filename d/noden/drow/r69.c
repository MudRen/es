
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("garden","神宫後庭花园");
       set_long(@C_LONG
这个大约跟神殿同大小的花园种满了各式各样的奇异花
卉，你看到西边有一个小湖，上面还有个小岛，也种了各种
不同的植物，似乎有人在这边打扫，庭园的尽头有一扇门，
不过锁得紧紧的，看来是不能打开了。
C_LONG );
       set("exits",([
                     "southeast":"/d/noden/drow/r68"
                    ]));
       set("light",1);
       set("object",([
                      "linna":"/d/noden/drow/mob/m28"
                   ]));
}
