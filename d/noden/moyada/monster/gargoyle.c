#include "../moyada.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(9);
	set_name( "Gargoyle", "石像鬼" );
	add ("id", ({ "gargoyle", }) );
	set_short( "石像鬼" );
	set_long( @C_LONG
能使用背部的翅膀在天空中飞翔, 不过比较喜欢居住在黑暗的角落. 会使用
头上的两只角, 攻击敌人. 
C_LONG
	);
	set( "alignment", -600 );
    set( "gender", "male" );
    set( "race", "daemon" );
    set( "unit", "只" );
	set_perm_stat( "dex", 14 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 7 );
	set_perm_stat( "con", 13 );
	set_perm_stat( "piety", 5 );
	set_perm_stat( "karma", 10 );
	set ("max_hp", 250);
	set ("hit_points", 250);
	set ("wealth", ([ "silver": 60 ]) );
	set_natural_weapon( 19, 10, 18 );
	set_natural_armor( 55, 20 );
    set ("weight", 550);
    set_c_limbs( ({ "身体", "头", "脚", "角"}) );
    set_c_verbs( ({ "%s用角刺%s", "%s狂踢%s", "%s猛撞%s",}) ); 
    set ("exp_reward", 950 );
    set_experience(10000);
}
