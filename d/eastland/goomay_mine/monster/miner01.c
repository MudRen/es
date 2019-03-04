#include <mudlib.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(11);
	set_name( "old miner", "老矿工" );
	add( "id", ({ "miner" }) );
	set_short( "老矿工" );
	set_long(@LONG
这个老人从年轻时就在段家工作了，老了之後段家顾用他来打理一些矿场上的琐事
，所以你可以问他一些在矿坑里的人和事．
LONG
);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "int", 15 );

	set( "natural_armor_class", 65 );
	set( "natural_defense_bonus", 20 );
	set_natural_weapon( 23, 18, 26);
	set( "time_to_heal", 2 );
	set( "max_hp", 400 );
	set( "hit_points", 400 );
	set( "gender", "male" );
	set( "alignment", 800 );
	set( "wealth/silver", 200 );
        set( "inquiry",([
             "detonation" : "我不清楚，不过你可以找那些命大的人问问．\n",
             "troll" : "我只知道他们是请来看守魔法磁铁矿(magic magnetite)的．\n",
             "ghost":
"我就是不知道才在奇怪啊？算了看在你智商有点不太够的\n"
"份上指点你一条明路吧．问看看老酒鬼知不知道．\n"
]));
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"老矿工喃喃自语道: 大厅的南边常有一些奇怪声音发出来!不知道是不是有鬼(ghost)?\n",
		"老矿工说道: 自从有一天矿场发生大爆炸(detonation)後,一些人都变得怪怪的．\n",
	}));
	}