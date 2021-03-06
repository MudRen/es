#include "../../story.h"
inherit WMOB"warmob";

void create()
{
	::create();
	set_level(19);
	set_name( "Chi-eu", "蚩尤" );
	add( "id", ({ "chi-eu","eu","chi" }) );
	set_short( "蚩尤" );
	set_long(@LONG
你眼前所见的是一位高大雄壮的巨人。他面上青筋暴浮，两个大眼如铜铃，电射出绿
光，一个身子几乎没穿，露出相当粗壮的臂膀，口发如虎般的声响。蚩尤现在正带领
大军四处烧杀掳掠。
LONG
	);
	set( "race","巨人");
	set( "gender","male");
	set( "unit", "位" );
	set( "alignment", -1000 );
	set_natural_weapon(10,13,22);
        set( "special_defense", ([ "all":45,"none":40 ]) );
        set( "aim_difficulty",
           ([ "critical":50, "ganglion":40,"vascular":50, "weakest":50 ]));
        set("stun_difficulty",100);
	set( "wealth/silver", 200 );
	set( "max_hp",5000);
	set( "hit_points",5000);
	set( "spell_points",1000);
	set( "killer", 1 );
	set( "pursuing",1);
        set( "moving",1);
        set( "speed",40);
        set( "wimpy",500);
        set( "war_points", 700 );
	set_perm_stat( "str", 30);
	set_perm_stat( "dex", 25 );
	set_perm_stat( "int",15);
	set_temp("detect_hide",1);
	set_skill( "parry",100 );
	set_skill( "block", 100 );
        set_skill( "dagger", 100);
        equip_armor(WARM"chi_shield");
        equip_armor(WARM"chi_skirt");
        equip_armor(WARM"chi_cloak");
        equip_armor(WARM"chi_helmet");
        wield_weapon(WWEA"chi_blood");
        set("tactic_func","my_tactic");
}
void init()
{
    add_action("do_embattle","embattle");
    ::init();
}
int do_embattle(string arg)
{
   tell_room(environment(this_object()),"蚩尤狂笑道：想围殴，门都没有！");
   return 1;
}
int my_tactic()
{
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(10) > 1 ) return 0;
    tell_room(environment(),"\n从蚩尤口里吐出一团绿色的气体！！\n\n");
    set("spell_points",1000);
    hurt_all("evil",60);
    hurt_all("poison",60);
    return 1;    
}
void die()
{
   ::die();
   tell_room(environment(),"\n\n从天空中传来蚩尤声音：哼，卷土重来的我有那有那麽容易死，这只不过是\n我的一个分身而已，我现在就去找黄帝那个狗贼算帐。哈哈哈哈....\n");
}