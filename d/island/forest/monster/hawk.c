#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Magic Hawk","魔鹰");
    add("id",({"hawk","eagle"}) );
    set_short("魔鹰");
    set_long(@LONG
这是一只可怕的鹰，正疯狂的拍动它的翅膀，对你怒目而视。
LONG
            );
    set("unit","只");
    set("alignment",-800);
    set("weight",600);
    set_perm_stat("str",17);
    set_perm_stat("dex",16);
    set("hit_points",300);
    set("max_hp",300);
    set("killer",1);
    set("pursuing",1);
    set("exp_reward",6000);
    set_natural_weapon(40,30,40);
    set_natural_armor(45,25);
    set("unbleed",1);
    set("c_killer_msg","突然间，魔鹰伸展双翼及利爪向你冲了过来！");
    set_skill("dodge",80);
    set_c_verbs( ({"%s的尖喙啄向%s","%s的利爪抓向%s","%s的翅膀扫向%s"}) );
    set_c_limbs( ({"背心","利爪","颈部","额头","翅膀"}) );
    set("alt_corpse",TWEP"dagger1");
    set( "death_msg","%s\n");
    set( "c_death_msg","%s说:今後我愿跟随您，主人！随後幻化成一把匕首....\n");
 }
