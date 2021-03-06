#include "mudlib.h"
#include <daemons.h>

inherit MONSTER;

void init()
{
add_action("do_sit","sit");
}
void create ()
{

    ::create();
    set_level(15);
    set_name("Officer Sophia","书记官 索菲亚");
    add("id",({"officer","sophia"}) );
    set_short("书记官 索菲亚");
	set_long(@C_LONG
书记官 索菲亚是一个绿发长耳的女孩，有著可爱的脸庞与灿烂的笑容。
她现在为诺达尼亚的图书馆工作，由於耶拉曼国王对冒险很有兴趣，特地派
她来冒险者公会收集资料，如果你有任何有关冒险的故事，可以在旁边的皮
椅上坐下来，慢慢讲给她听，你将会因此而获得一些报酬。
C_LONG
	);
    set("alignment",500);
    set( "gender", "female" );
    set( "race", "elf");
    set( "unit", "个" );
    set_perm_stat( "dex",23);
    set_perm_stat( "str",18);
    set_perm_stat( "int",22);
    set_perm_stat( "karma",23);
    set_skill("unarmed",70);
    set_skill("parry",60);	
    set ("max_hp",400);
    set ("hit_points",400);
    set ("wealth", ([ "gold":100]) );
    set_natural_weapon(20,10,20);
	set_natural_armor(50,40);
	set ("aim_difficulty",([ "weakest":30,"vascular":10]) );
	set("special_defense", (["fire":10,"none":20,"cold":-10]) );
    set ("weight", 400);
    wield_weapon("/d/adventurer/hall/weapons/claw");
    equip_armor("/d/deathland/armour/cloth05");
    equip_armor("/d/deathland/armour/necklace01");
    equip_armor("/d/deathland/armour/gloves01");
}
int do_sit()
{
     int explore,total_points,EXPLORE1,num;
     explore  = (int)this_player()->query_explore_points();
     total_points=EXPLORE_D->query_total_explore(); 
     EXPLORE1=explore*10000/total_points;
     if (EXPLORE1 > 10000) EXPLORE1 =10000;
     if((string)this_player()->query("class") != "adventurer" ) {
     write("书记官 索菲亚说道: 你又不是冒险者，来这凑什麽热闹?\n");
     return 1;
     }
     if ((int)this_player()->query_level() < 4 )
     return notify_fail("书记官 索菲亚说道: 我想你的等级太低了，可能对我没有帮助。\n");
     if ((int)this_player()->query("adv_cash") < EXPLORE1 ) {
     tell_object(this_player(),set_color("你开始叙述你最近的冒险事迹，索菲亚聚精会神的记录，不时流露出崇拜的眼神。\n\n", "HIG",this_player()) );
     	        tell_room( environment(this_player()),"\n"+
		this_player()->query("c_name")+"坐下来开始加油添醋的吹嘘自己的冒险事情" 
		"但是索菲亚仍然是专心的倾听。\n\n", this_player() );
     num = EXPLORE1 - (int)this_player()->query("adv_cash");
     this_player()->add("wealth/gold",num);
     this_player()->set("adv_cash",EXPLORE1);
     write("书记官 索菲亚说道: 谢谢你，这些是给你的报酬\n");
     if((string)this_player()->query("gender") != "male" ) return 1;
     else 
     write("书记官 索菲亚轻轻地在你的脸颊上亲了一下.\n");
     return 1;
     }
     write("书记官 索菲亚说道: 你并没有更好听的冒险故事。\n"
           "多加点油，我对你有很高的期望....\n");
     return 1;      
}     
