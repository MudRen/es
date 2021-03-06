//#pragma save_binary

#include "../mage.h"
// Let players can use flare [2] , original limit is flare [1], modified in 1995/2/29

inherit "/d/mage/study1";
inherit ROOM;

void create()
{
	::create();
	set_short("A empty room", "黑魔法图书室");
	set_long( @LONG_DESCRIPTION
NEED TRANSLATE HERE.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
这里是专门收藏黑魔法卷轴的收藏室，据掌管这间收藏室的人估计，大约有
百分之九十以上目前已知的黑魔法咒语都能在这里找到，在你的面前有一本厚重
的目录(catalog)，你可以安静地在这里研读(study)魔法书，或研究提升(raise
)魔法等级的知识，往东可以回到魔法图书馆的大厅。
C_LONG_DESCRIPTION
	);
    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"east" : MAGE"library" ]) );
	set( "item_func", ([
		"catalog": "view_catalog" ]) );
	set_spells( ([
		"ether-bolt"  : ({ "black-magic", 20, 7, 10, 130 }),
		"lightning"   : ({ "black-magic", 50, 3, 10, 200 }),
		"flare"       : ({ "black-magic", 80, 2, 10, 500 }),
     "mirror-shield"  : ({ "black-magic", 40, 3, 15, 160 }),
     "energy-shield"  : ({ "black-magic", 40, 3, 15, 110 }),
	]) );
	reset();
}
