#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "wing boy", "羽民小弟弟" );
	add( "id", ({ "boy" }) );
	set_short( "羽民小弟弟" );
	set_long(@C_LONG
一个居住在羽民村里的小孩。他年约十一、二岁，头上梳了两个ㄚ髻，正快乐地在
这片草原上嬉戏玩耍，一对大眼睛骨溜溜地盯著你瞧，不时在你周围打转，活泼极
了。
C_LONG
        );
	set( "gender", "male" );
	set( "race","羽民" );
	set( "alignment", 100 );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(40,2);
        set_natural_weapon( 11,5,8 );
        set( "player_invisible" ,1 );
}
