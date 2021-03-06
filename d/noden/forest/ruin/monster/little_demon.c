#include "../ruin.h"

inherit MONSTER;

object victim;
void create ()
{
	::create();
	seteuid( getuid() );
	set_level(11);
	set_name( "little demon", "小恶魔" );
	add ("id", ({ "daemon", "demon", }) );
	set_short( "小恶魔" );
	set_long( @C_LONG
黑魔从冥黑的世界呼唤出来的恶魔，在魔界的地位不高，但会死心塌地的
为主人卖命，听从主人的命令，至死方休。
C_LONG
	);
	set( "alignment", -1000 );
    set( "unit", "只" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 17 );
	set_perm_stat( "con", 18 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 19 );
	set ("max_hp", 280);
	set ("hit_points", 280);
	set_natural_weapon( 40, 18, 30 );
	set_natural_armor( 70, 19 );
	set ("pursuing" ,1);
	set ("aggressive", 1);
    set ("weight", 400);
    set ("exp_reward",2400 );
    set ("unbleeding", 1);
    set ("aim_difficulty", ([ "critical":30, "weakest":15, "ganglion":40 ]) );
    set ("special_defense", ([ "all":25, ]) );
    set_experience(20000);
    set_skill("dodge",50);
    set_c_verbs( ({ "%s用爪子抓%s", "%s用角刺%s", "%s踢%s",
                    "%s咬%s", "%s用镰刀横劈%s", }) );
    set_c_limbs( ({ "头", "身体", "脚", "角", "翅膀", }) );
    wield_weapon(OBJ"scythe");
}
