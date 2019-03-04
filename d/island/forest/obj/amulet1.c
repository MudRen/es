#include "../tsunami.h"

inherit ARMOR;

void create()
{
      set_name("Royal amulet","王者护身符");
      add("id",({"amulet"}) );
      set_short("王者护身符");
      set_long(@LONG
这是树雷王族中代表最高权力的象徵信物，相传这是守护灵赐给王家嫡长的信物！
LONG
              );
      set("unit","枚");
      set("type","misc");
      set("material","element");
      set("armor_class",0);
      set("defense_bonus",8);
      set("special_defense",(["fire":30,"cold":20,"evil":-40]) );
      set("weight",10);
      set("no_sale",1);
      set("value",({100,"gold"}) );
}              
                    
