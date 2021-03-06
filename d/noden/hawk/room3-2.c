
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("长老室");
        set("light",1);
        set_long( @LONG_DESCRIPTION
这里是鸟人族长老办公休息的地方，墙上挂著许多稀奇古怪的东西，
都是鸟人长老年轻时在外游历所得到的战利品。金色的光线把整个房间照
的有如白昼一般，但是你却无法感觉出光线的来源究竟是哪儿。
LONG_DESCRIPTION
        );
        set( "objects", ([
                "elder" : MOB"small_elder",
                "guard1" : MOB"guard",
                "guard2" : MOB"guard",
                        ]) );

        set( "exits", ([
                "south" : HAWK"room3-1",
                     ]) );
        set("pre_exit_func",(["south" : "go_south" ]) ) ;
        reset();
}//end of creat

int go_south()
{
        object caster;
        int aa;

        caster = present("elder");
        if (!caster) return 0;
        aa = (int)caster->query_temp("no_way_out");

        if (aa)
        {
                write("四周冰雪遮住了你的视线让你没办法离开这里。\n");
                return 1;
        }
        return 0;
}
