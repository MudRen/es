//#pragma save_binary

// translation done 2-24-94. -Elon (having hard time translating)

#include <mudlib.h>
#include <stats.h>
#include <guilds.h>

#define BOARD "/u/s/sage/guild/killer_board"

inherit GUILD;
inherit DOORS;
void create()
{
    object guild_master;

        ::create();

    set_short("鬼屋");
        set_long(
                 @C_LONG_DESCRIPTION
    你进了一间乌灯黑火的房间，一阵寒风吹来，不觉打了个哆嗦，你的第六
感告诉你，在房子的某个角落，正有一双狼一样的眼睛在盯着你，只要你一放
松警戒，这双眼睛就会向你扑来。然而在这这间房子里，却看不到半个人影。
    在角落里有一张已经发霉的纸(paper)，你用尽所有精力，才依稀看出一点
眉目。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "c_item_desc", ([
                "paper" : @LONG_TEXT
———————————————————————————————————
破纸上写著:
    本公会为世上最强之公会，加入后能学到世上无双的武功，可以称霸世界，
名额有限，欲入从速。
    详细入会情形请用 help guild 阅读说明。
    有关本公会的限制与情形请用 help healers。
———————————————————————————————————
LONG_TEXT
 ]) );
    set( "exits", ([
            //    "north": "/d/healer/building/healer_shop",
            //    "east" : "/d/healer/building/healer_inner",
            //    "west" : "/d/noden/bluesand/alley2",
            //    "south": "/d/healer/building/healer_operate",
                  "north": "/u/s/sage/guild/gc",
        ]) );


        set( "pre_exit_func", ([
                "north" : "check_healer" ]) );
    //guild_master=new("/d/healer/building/monsters/healer");
    //guild_master->move(this_object());
       create_door("north", "south", ([
                    "keyword"       : ({ "tree door", "door" }),
                    "name"          : "tree door",
                    "c_name"        : "木门",
                    "c_desc"        : "一扇破烂的木门",
                    "status"        : "closed",
        ]) );


  //    set_guild("keller")
        BOARD->frog();
        reset();
}


