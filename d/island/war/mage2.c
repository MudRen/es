#include "../island.h"

inherit IWAR"i_warvalue";

void create()
{
	::create();
	set_level(10);
	set_name( "Light teeth", "光牙" );
	add("id", ({"teeth"}) );
        set_short( "魔兽「光牙」" );
	set_long(@C_LONG
一只全身发光，四处乱撞的魔兽。
C_LONG
	);
	set_perm_stat("str", 10 );
	set_perm_stat("dex", 11 );
	set_skill("dodge", 40 );
	set_skill("tactic", 70 );
	set("tactic", "melee" );
	set("killer", 1);
	set("pursuing",1);
	set("max_hp", 200);
	set("hit_points", 200);
	set("justice",1);
	set_natural_armor(45,10);
	set_natural_weapon(20,12,20);

       set("c_killer_msg","突然地上射出一道光线，在冲向天空转了个弯後，向你袭来！\n");
       set_c_verbs( ({"%s突然笔直的射向%s","%s转了个弯儿向%s冲了过去",
              "%s在地上蜿蜒前进突然咬向%s"}) );
       set_c_limbs( ({"门面","牙齿","头部","身躯"}) );
       set("c_death_msg","%s说：主人，请接受我的效忠！说著说著化成一把短刃....\n");
       set("alt_corpse",IWARO"shortblade1");   
}
