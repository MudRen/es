
#include <mudlib.h>
inherit OBJECT;

void create()
{
       set_name("evil dagger","邪恶匕首");
       set_short("evil dagger","邪恶匕首");
       add("id",({"dagger"}));
       set_long(@C_LONG
这柄匕首的握柄上画有一条有八条尾巴的怪物，刀锋黝
黑，极其锐利，并且散发出一阵阵邪气，由於邪气逼人
，依你的经验，这并不适合做为你战斗用的武器。
C_LONG );
      set("unit","柄");
      set("weight",8);
      set("no_sale",1);
      set("no_clean",1);
      set("value",({410,"silver"}));
}
