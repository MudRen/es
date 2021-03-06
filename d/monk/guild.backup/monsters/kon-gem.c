#include "saulin_monk.c"

void create()
{
	::create();
	set_level(5);
	set_name( "kon gem", "老僧空见" );
	add ("id", ({ "kon", "gem","monk" }) );
	set_short( "老僧空见" );
	set_long( @LONG
空见大师年纪非常大了，身材极瘦而又枯\乾，但双目中却泛出无比的慈祥
他精研金刚不坏体神功\，向来是打不还手，骂不还口。昔日武林大寇黑风
掌谢震即是被他感化，投如佛门。
LONG
	);
    set( "alignment",2500);
    set( "gender", "male" );
    set( "race", "vampire" );
    set( "unit", "位" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 18);
	set_skill("dodge",100);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 999);
	set("max_fp", 500);
	set("hit_points", 999);
	set("force_effect", 2);
	set("force_points", 500);
	set("forgetful", 1);
          set("defense_skill",CLASS"body_def");    
          set("monk_gonfu/body-def",10);
	set("wealth/gold", 10);
	set_natural_weapon( 30, 15, 30 );
	set_natural_armor( 90, 65 );
        set("weight", 500);
}
