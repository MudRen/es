#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(16);
    set_name("Shu Ning","徐宁");
    add("id",({"shu","ning"}) );
    set_short("徐宁");
	set_long(@C_LONG
外号金□手，延安府人，重义轻利，善使一把钩镰□，武艺不凡，进退有节，
目前为梁山马军大骠骑兼先锋使。
C_LONG
	);
    set("alignment",300);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "个" );
    set_perm_stat( "dex",20);
    set_perm_stat( "str",25);
    set_perm_stat( "int",20);
    set_perm_stat( "karma",24);
    set_skill("trusting",90);	
    set_skill("parry",80);
    set ("max_hp",400);
    set ("hit_points",400);
    set ("time_to_heal",5);
    set ("wealth", ([ "gold":220]) );
    set_natural_weapon(20,13,21);
	set_natural_armor(38,20);
	set ("aim_difficulty",([ "weakest":20,"vascular":30]) );
	set("special_defense", (["magic":30,"none":10]) );
    set ("weight", 400);
    equip_armor(TARMOR"one_hood");
    wield_weapon(TWEAPON"hooklance");
    equip_armor(TARMOR"mirror");
    equip_armor(TARMOR"iron_plate");
    equip_armor(TARMOR"darkgreen_cloak");
    equip_armor(TARMOR"cowskin_boots");
}

