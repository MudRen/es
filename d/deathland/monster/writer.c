
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "Dwarf poet", "矮人诗人" );
	add ("id", ({ "poet","dwarf" }) );
	set_short( "Dwarf writer", "矮人诗人" );
	set_long(@DESC
一个矮人诗人,她正在寻找写作的灵感(afflatus)而散步在小路上,为了寻找
灵感她已经好几天没有睡觉了.
DESC
     );
    set( "alignment", -100 );
    set( "gender", "female" );
    set( "race", "dwarf" );
    set( "unit", "个" );
	set_perm_stat( "str", 7 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon(4,2,6);
	set_natural_armor(26,0);
    set ("weight", 300);
    set ("chat_chance", 25);
    set ("chat_output", ({
            "这作家说:可能一个好的作品需要一个好的灵感,但是那里去找寻灵感呢?\n",
	    }) );
	set ( "inquiry",([
	      "afflatus":"@@ask_afflatus",
	      "muse":"@@ask_muse",
	      "queen":"@@ask_queen",
	      ]) );
	wield_weapon(Weapon"/dagger03");
    equip_armor(Armour"/cloth04");
}

void ask_afflatus(object who)
{
     who->set_explore("deathland#38");
     tell_object(who,
	"如果有传说中谬思(Muse)泉的泉水的话,或者能帮我找回我的灵感.\n");  
     return;
}

void ask_muse(object who)
{
     tell_object(who,@MSG1
一个诗人之泉,据说正确的位置是在於死亡大地的最深处,但是
详细的位置没有几个人知道,
对了,或许安洛长老知道,他是个很有智慧的人
MSG1
                 );
}

void ask_queen(object who)
{
     tell_object(who,"可怜的皇后, 全国的人民都为了她在担心著\n");
}
