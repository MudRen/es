#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Huge Turtle","巨龟");
    add("id",({"turtle"}) );
    set_short("巨龟");
    set_long(@LONG
这是一只巨大的老海龟，充满磨痕的龟壳及满布皱纹的皮肤，在在显示了它所走过
的岁月是多麽的悠久；对於你突然的出现，它似乎显得有点惊讶，或许此处难得有其
他生物来访吧！千万不要惊扰它哦，一但让它生气起来，可不是哄哄它就没事的哦！
LONG
            );
    set("unit","只");
    set("alignment",-1500);
    set("weight",2000);
    set("likefish",1);
    set_perm_stat("str",25);
    set("hit_points",1000);
    set("max_hp",1000);
    set_natural_weapon(40,20,30);
    set_natural_armor(50,40);
    set("unbleed",1);
    set_skill("parry",80);
    set_c_verbs( ({"%s的头顶向%s","%s的巨掌推向%s","%s的尾巴扫向%s"}) );
    set_c_limbs( ({"尾巴","利爪","颈部","额头"}) );
    set("alt_corpse",TOBJ"boot1");
    set("death_msg","%s\n");
    set("c_death_msg","%s和缓的伏在你面前，恭敬的称呼一声：主人！接著化成一双鞋子!\n");
    }