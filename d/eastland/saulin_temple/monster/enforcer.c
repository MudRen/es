#include "saulin_monkb.c"

void create()
{
        ::create();
        set_level(15);
        set_name( "commandment enforcer", "戒律院执事僧" );
        add("id",({ "monk","enforcer" }));
        set_short("戒律院执事僧");
        set("unit","位");
        set_long(@C_LONG
他是一位看起来很严肃的和尚，手持戒棍，一副绝不可侵犯的样子... 
戒律院负责少林子弟的惩罚处置，犯了任何戒律都由他们来制裁和处罚。
所以，劝你没事的话还是离他们远一点为妙。 
C_LONG
        );
        set("alignment",600);
        set("wealth/gold", 18);
        set_perm_stat("str",20);
        set_perm_stat("dex",25);
        set_perm_stat("kar",23);
	set_natural_weapon(-4,2,10);
        set_natural_armor(53, 19);
        set("max_fp",1800);
        set("force_points",1800);
        set("max_hp", 500);
        set("hit_points", 500);
	set("attack_skill",CLASS"fu_mo");
	set("gonfus/fu-mo",100);
        set("special_defense",([ "none" : 40, "all" : 20 ]));
        set("aim_difficulty", ([ "critical" : 35, "vascular" : 40, ]) );
        set_skill("parry",100);
	set_skill("bo",80);
        set("gender", "male");
        set("race", "human");
        wield_weapon( SAULIN_OBJ"rule_staff" );
        equip_armor( SAULIN_OBJ"necklace01" );
        equip_armor( SAULIN_OBJ"yellow_pallium" );
}
