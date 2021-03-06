#include "iigima.h"
inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short( "tunnel","通道");
        set_long(
@C_LONG
这里是黑暗精灵村的通道，由於整个村落都是在地底下的深处，这
里阴凉而空气清新，广大的通道宽广平坦，靠近石壁的地方，都雕刻有
蜘蛛，和蛇的图案。
C_LONG
        );
        set( "light",0 );
        set( "exits", ([

                     "east" : DROW"r05",
                     "west" : DROW"r03",
                     "north": DROW"r01",
        ]) );
        set("objects", ([
                "guard#1": DRO"final_guard",
                "guard#2": DRO"final_guard",
        ]) );
        set( "pre_exit_func", ([
                "north" : "check_guard" ]) );
        reset();

        create_door( "north", "south", ([
                "keyword" : ({ "iron door", "door" }),
                "name" : "iron door",
                "c_name" : "大铁门",
                "status" : "locked",
                "c_desc" : "一扇冰冷的大铁门，。\n",
                "lock" : "IRON_DOOR"
        ]) );
        reset();
}
int check_guard()
{
        if ( present("guard", this_object() ) ) {
                write("守卫说道: 里面是祭祀的神坛，你不能过去啦！\n");
                return 1; }
        return 0;
}
