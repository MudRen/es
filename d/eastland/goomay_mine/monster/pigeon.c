#include <../zeus.h>        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(15);
       set_name( "pigeon", "小鸽子" );
       set_short( "pigeon","小鸽子");
       set("unit","只");
       set_long(@LONG
你看见一只可爱的动物，正在地上轻快的啄食著，他用一双乌黑的
小眼睛正望著你，无辜的表情好像是在对你说，不要伤害我．
LONG
);
       set_perm_stat("dex", 20);
       set ("weapon_class1", 20);
       set ("tactic_func","my_tactic");
       set ("armor_class", 25);
       set_c_verbs(({"%s用它的尖嘴向%s刺去"}));
       set_c_limbs(({"身体","耳朵","脚部","头部"}));
}
int my_tactic()
{  object obj;
   tell_room(environment(this_object()),
   "小鸽子回头望了望你，然後很不屑地飞走了，彷佛在讥笑你的无知．\n"
   );
   obj=present("pigeon");
   obj->remove();
   return 1;
   }
