#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(16);
       set_name( set_color("Crab","HIR"),set_color("小螃蟹","HIR") );
       add("id",({"crab"}) );
       set_short( set_color("小螃蟹","HIR") );
       set("unit","只");
       set_long(set_color("
    
      ∪        ∪
     □ ⊙  ⊙ □
    《\\┴—┴/《    　一只全身赤红的小螃蟹，它正向你炫著它的两个大
    《｜    □《　　   巨螯。
     □———□


       \n","HIR"));
       set_perm_stat("str",25);
       set_natural_armor(75,0);
       set_natural_weapon(27,18,29);
       set_c_verbs(({"%s用它的巨螯向%s攻击"}));
       set_c_limbs(({"身体","头部","壳"}));
}

