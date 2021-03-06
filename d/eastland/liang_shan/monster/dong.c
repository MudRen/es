#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(19);
    set_name("Dong Ping ","董平");
    add("id",({"dong","ping"}) );
    set_short("董平");
	set_long(@C_LONG
外号双□将，河东上党人，心灵机巧，好逞骁勇，三教九流，无所不通，品竹调
弦，无所不会。使双□，神出鬼没，现为梁山泊马军五虎将中第五大将。
C_LONG
	);
    set("alignment",500);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",20);
    set_perm_stat( "int",22);
    set_perm_stat( "karma",27);
    set_skill("thrusting",100);
    set_skill("two-weapon",100);	
    set_skill("tactic",100);
    set_skill("parry",90);
    set ("max_hp",900);
    set ("hit_points",900);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(60,32);
	set ("aim_difficulty",([ "weakest":50,"vascular":50]) );
	set("special_defense", (["magic":50,"none":20]) );
    set ("weight", 400);
    equip_armor(TARMOR"iron_hat");
    wield_weapon(TWEAPON"silver_spear");
    wield_weapon2(TWEAPON"silver_spear");
    equip_armor(TARMOR"beastface");
    equip_armor(TARMOR"purple_plate");
    equip_armor(TARMOR"green_cloak");
}

