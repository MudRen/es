#include <mudlib.h>
inherit "/d/monk/guild/train_gonfu.c";
inherit ROOM;

void create()
{
        room::create();
        set_short("疗伤神功\练功\房");
        set_long( @LONG_DESCRIPTION
这里是少林寺专门教导各种不同运功\疗伤武学的练功\房，大部份基础的疗伤
武功\秘笈都放在这里，一些使用注意说明请看布告栏(board)。
在你面前是一排泛黄的羊皮纸 (paper)，你可以根据自己的武学造诣选择你能够
学习的武功\，然後在此处训练(train)，往西可以回到罗汉堂。 
LONG_DESCRIPTION
        );
   
    set("c_item_desc",([
         "board":@BOOK
疗伤神功\是用来恢复你在战斗中所受伤害的功\夫。
使用方法是 eungon [功\夫名称]

1. 轮指点穴: 点穴止血
2. 运功\逼毒: 以你的穴道学知识及内力大小，运功\将体内毒素逼出
3. 其它: 大都为疗伤用，也许\有其它效果  

BOOK
        ]));         
        set( "no_monster", 1);
        set( "light", 1 );
        set( "exits", ([ 
                "west" : "/d/monk/guild/monk_guild",
				"east" : "/d/monk/guild/monk_hoard_room" ]) );
        set( "item_func", ([
                "paper": "view_catalog" ]) );

        // setup type of gonfus & name of gonfus.
        set_gonfu_type("heal");
        set_gonfus( ([
//              "gi-chi"  : ({ "heal-cycle",  5,   200 }),
                "bi-du"   : ({ "heal-cycle", 65,  7500 }),
                "lun-chi" : ({ "heal-cycle", 25,  2000 }),
                "pu-ty"   : ({ "heal-cycle", 50,  5000 }),
                "gun-in"  : ({ "heal-cycle", 85, 20000 }),
        ]) );
        reset();
}
