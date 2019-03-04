#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Combat Cloth","树雷战斗装");
      add("id",({"cloth"}) );
      set_short("树雷战斗装");
      set_long(@C_LONG
这是树雷王家传统的战斗装，外观虽然不十分起眼，由於质地轻巧，深受王族的喜爱;
当王族穿上它时，它就能与之产生共鸣，给予使用者十分恰当的保护!
C_LONG
              );
      set("unit","件");
      set("type","body");
      set("material","element");
      set("armor_class",25);
      set("defense_bonus",2);
      set("weight",130);
      set("value",({1500,"silver"}) );
}