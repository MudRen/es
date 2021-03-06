#include "../takeda.h"

inherit "/std/teacher";
inherit MONSTER;


void init()
{
	::init();
	teacher::init();
}

void create ()
{

	::create();
    set_level(19);
    set_name("Hu Yan Zuo","呼延灼");
    add("id",({"hu","yan","zuo"}) );
    set_short("呼延灼");
	set_long(@C_LONG
外号双鞭呼延灼，为人忠义双全，善使两条水磨八□钢鞭，但现在几乎找不到对手
了，所以现在只拿一条钢鞭，现为梁山泊马军五虎将中第四大将。
C_LONG
	);
    set("alignment",700);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",29);
    set_perm_stat( "str",20);
    set_perm_stat( "int",17);
    set_perm_stat( "karma",30);
    set_skill("whip",100);	
    set_skill("dodge",70);
    set_skill("parry",90);
    set ("max_hp",950);
    set ("hit_points",950);
    set( "chat_chance",5);  
    set("chat_output",({"呼延灼叹道: 可惜我一身出神入化的鞭艺，竟没有传人...\n"}));
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(60,32);
	set ("aim_difficulty",([ "weakest":50,"vascular":50]) );
	set("special_defense", (["magic":50,"none":20]) );
    set ("weight", 400);
    set_lessons( ([
	"whip": ({ 120, 80 })
	]) );
    equip_armor(TARMOR"iron_cap");
    wield_weapon(TWEAPON"steel_whip");
    equip_armor(TARMOR"beastface");
    equip_armor(TARMOR"leave_plate");
    equip_armor(TARMOR"nail_cape");
    equip_armor(TARMOR"eagleclaw_boots");
}
int check_trainee(object trainee)
{
	if( (string)trainee->query("class")=="adventurer" 
	&& (int)trainee->query_level() > 4 )
		return 1;
	else
             return notify_fail( 
                    "呼延灼说道: 我只教够资格的冒险者，你的条件不合！\n" );
}

