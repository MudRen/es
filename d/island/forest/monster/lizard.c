#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(14);
    set_name("Huge Lizard","大蜥蜴");
    add("id",({"lizard"}) );
    set_short("大蜥蜴");
    set_long(@LONG
一只巨大的蜥蜴，慵懒的趴在你的面前，口中不断的吐信，彷佛在探查你的来意
似的。嘴边遗留著尚未嚼碎的白骨，天啊，这是只肉食性的大爬虫，你可得小心罗
，以防它趁人不备时偷袭。
LONG
            );
    set("unit","只");
    set("alignment",-2000);
    set("weight",2000);
    set("max_hp",500);
    set("hit_points",500);
    set_natural_weapon(20,21,30);
    set_natural_armor(60,35);
    set("unbleed",1);
    set_skill("dodge",80);
    set_skill("parry",60);
    set_skill("unarmed",50);
    set_perm_stat("str",25);
    set_perm_stat("dex",23);
    set_c_verbs( ({"%s的舌头卷向%s","%s用利爪刺向%s","%s的尾巴扫向%s"}) );
    set_c_limbs( ({"尾巴","利爪","颈部","额头","舌头"}) );
    set("alt_corpse",TOBJ"shield2");
    set("death_msg","%s\n");
    set("c_death_msg",
    "%s和缓的伏在你面前，恭敬的称呼一声：主人！一阵白烟之後，眼前只留下一面盾!\n");
}
