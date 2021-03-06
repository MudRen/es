#include <../goomay.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "merchant", "鱼贩" );
	set_short( "鱼贩" );
	set_long(
		"他是一个十分精壮结实的鱼贩，正在吆喝著他的鱼货。\n"
	);
	set( "race", "orc" );
	set( "gender", "male" );
	set( "alignment", 200 );
	set_skill( "dodge", 60 );
	set( "wealth/gold", 15 );
        set_natural_armor( 40, 20 );
        set_natural_weapon( -16, -5, -5);
        set_perm_stat( "str", 14 );
        set_perm_stat( "int", 12 );
        set_perm_stat( "dex", 14 );
        set_skill( "polearm", 70 );
        set_skill( "parry", 80 );
        set( "hit_points", 300 );
        set( "max_hp", 300 );
        wield_weapon( Obj"balance" );
        equip_armor( Obj"pearl_ring" );

        set( "inquiry", ([
                "hunter" : 
@WINE
猎人跟我不熟啊，我们只是点头之交啦，他打猎我卖鱼
，如此而已，不过最近真的都不见他的踪影，我也蛮担心的，不知道
他是不是出了什麽意外了，你可以去找他，他就住在旧城，向北走就
是了。
WINE
]));

}

