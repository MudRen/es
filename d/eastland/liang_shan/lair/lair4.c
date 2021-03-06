#include <../takeda.h>
#include <conditions.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "水池中" );
	set_long(@C_LONG
这里是一个小池子的底部，池底是坚硬的石壁，上面长满了厚厚的水生植物
在不远的前方，好像有一大块类似阶梯(ladder)的岩石，似乎可以通到上面
的一个大岩隙，一些微风从那个岩隙中透出，那里也许可以通到外面去喔。
C_LONG	
	);
        set( "exits", ([
                "out" : TROOM"lair/lair2"
        ]) );
        
        set( "objects", ([
                "sco1" : TMONSTER"scopio",
        ]) );
                set("c_item_desc",(["ladder":
                "一块像梯子的大石头，从它光滑平整的表面来看，似乎不是 \n"
                "天然的物品，也许\你可以爬(climb)到上面去看看....\n"
                                                   ]));
        
        set("underwater",1);
        reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
  add_action("do_climb","climb");
}
int do_climb()
{
    if ( present("scorpion",this_object()) ) {
    write("别忙，先杀掉蝎子再过去吧....\n");
    return 1;
    }
    write("你游到那块岩石前，并且往上爬去..........\n");
    this_player()->move_player(TROOM"lair/lair5","你看到"+this_player()->query("c_name")+"从石缝爬了出去...\n");
    return 1;
}
int clean_up() { return 0; }
