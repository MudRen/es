#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(19);
    set_name("Lin Chong","林冲");
    add("id",({"lin","chong"}) );
    set_short("林冲");
	set_long(@C_LONG
外号豹\子头，东京人，生性耿直，爱交好汉，武艺精强，惯使丈八蛇矛
。本为东京八十万禁军总教头，因遭人陷害因而落草。现为梁山泊马军
五虎将中第二大将，他现在正忙著训练军士。
C_LONG
	);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",23);
    set_perm_stat( "int",20);
    set_perm_stat( "karma",25);
    set_skill("polearm",100);
    set_skill("parry",100);	
    set ("max_hp",1000);
    set ("hit_points",1000);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(60,32);
	set ("aim_difficulty",([ "weakest":50,"vascular":50]) );
	set("special_defense", (["magic":50,"none":20]) );
        set("stun_difficulty/ma",20) ;
    set ("weight", 400);
    equip_armor(TARMOR"iron_helmet");
    wield_weapon(TWEAPON"snake_polearm");
    equip_armor(TARMOR"beastface");
    equip_armor(TARMOR"floral_plate");
    equip_armor(TARMOR"floral_cape");
    equip_armor(TARMOR"whitejade_ring");
}

