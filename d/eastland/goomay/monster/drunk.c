#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "drunk", "醉汉" );
	set_short( "醉汉" );
	set_long(
		"一个浑身酒臭的醉汉，看他失意潦倒的样子，不知道是遭到什麽不幸\n"
		"还是自甘堕落。他正追著过路的人乱打，好像全世界的人都对不起他似的。\n"
	);
		set("aggressive",1);
        set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
		set_skill( "parry", 60 );
		set_skill("blunt",60);
		set( "gender", "male" );
		set( "race", "orc" );
		set( "alignment", -400 );
        set_natural_armor( 46, 18 );
        set_natural_weapon( -7,1,4);
                        	
		equip_armor( Obj"coat" );
		wield_weapon(Obj"club");
}
