#include "saulin_monk.c"

void create()
{
	::create();
	set_level(14); 
	set_name( "yeng dou", "远道" );
	add ("id", ({ "yeng", "dou","monk" }) );
	set_short( "远道" );
	set_long(@C_LONG
远道今年约二十六岁，他厌恶同族人以吸食别族的血为生的生存方式，所以 
不被同族人认同而遭追杀，一路逃至少林而获收留。他喜欢练刀法，一套无 
色刀法练的非常熟练。 
C_LONG
	);
    set( "alignment",1500);
    set( "gender", "male" );
    set( "race", "vampire" );
    set( "unit", "位" );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 16);
	set_perm_stat( "karma", 14);
	set_skill("longblade",80);
        set_skill("parry",70);
	set("special_defense", ([ "all":18, "none":15 ]) );
	set("max_fp", 800);
	set("force_effect", 2);
	set("force_points", 800);
	set("attack_skill",CLASS"wu_sur");
	set("gonfus/wu-sur",100);
	set("wealth/gold", 55);
	set_natural_weapon( 0, 7, 13 );
	set_natural_armor( 36, 34 );
    wield_weapon( SAULIN_OBJ"blade4" );
    equip_armor( SAULIN_OBJ"cloth5a" );
}
