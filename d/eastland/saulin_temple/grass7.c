// File: /d/eastland/saulin_temple/grass7.c
// Generated by Roommaker Wed Nov 22 23:36:14 1995

#include <mudlib.h>

inherit ROOM;

void create()
{
        ::create();
	set_short("_grass7","林中苍松");
	set_long( @DESC
你走到了一片草地上，四周都是松林，其中有三棵特别苍劲挺拔，矗立
在其他松树间显得十分矫矫不群，你注意到这三棵呈品字形排列的松树下都
有一个树洞，洞中各有一个老僧低头静思，你突然注意到三松之间的地面似
有一洞(cave)，黑黝黝的看不清。
DESC
	);
	set( "item_desc", ([ 
		"cave" : @MSG1
你想要走上前去看清楚这个洞穴，突然一阵如雷的语声传来：

	施主请留步，此处乃禁地，闲杂人等不得进入 !!

你吓了一大跳，那个发话者也不似故意要大声说话，好像是天生如
此，甚或内功\已达超凡入圣的境界，你直觉地提高警戒。
MSG1
 ]) );
        set( "exits", ([
             "south" : "/d/eastland/saulin_temple/grass6" ]) );
        set("pre_exit_func",([
            "cave" : "do_say" ]) );
	reset();
}

init()
{
     add_action( "do_say" , "say" );
}

int do_say(string arg)
{
     if( arg != "询问楞枷经的下落") {
         write("老衲已经说过, 请施主留步, 施主请自重\n");
	return 1;
     }
     if( this_player()->query_temp("book_quest/step")==3 ) {
         write(@MSG2
你只听得一个苍老的声音说道：嗯！是方丈派你来的啊！
好! 就让你进去吧。
一阵微风吹过, 你的身子突然腾空而起, 掉入一个漆黑的洞穴中。
MSG2
);
         tell_room( environment(this_player()),
   sprintf("你看到一道黑影将%s卷起,很快地不见了。\n",this_player()->query("c_name"))
              , this_player() );
         this_player()->move_player("/d/eastland/saulin_temple/cave","SNEAK");
                    }
   else {
         write("一个苍老的声音说道：抱歉！没有方丈的法旨, 谁也不能进去.\n");
	            }
      return 1;
}
