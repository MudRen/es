//#pragma save_binary

#include "farwind.h"

inherit ROOM ;

void create ()
{
        object obj ;

        ::create();
//      set_outside("farwind") ;
        set_short("露天英雄纪念馆");
        set_long(@C_LONG
你现在位於远风镇的露天英雄纪念馆。在草地中央有一座无名英雄
驻剑远眺的铜像(statue)，相传遭到意外而不幸死亡的灵魂，如果到这
里祈祷(Pray)的话，就有机会获得肉体再造的能力。
C_LONG
                );
        set( "light", 1 );
        set ("exits", ([
                "west" : FARWIND"bazz4",
                "east" : FARWIND"charch"
        ]) );
        set( "objects", ([
                "scroll": FARWIND"items/scroll" ]) );
        set( "no_monster", 1 );
        set( "PK_ZONE",1);
        set("item_desc",(["statue" :@C_WORD
这是一座威武的铜像，英雄的双眼眺望远方，坚毅的脸上泛著几许落寞忧伤。
在铜像的底座镶著一面铜牌，上面写著：

        英雄？什麽是英雄？
        我只祈祷神啊 !! 要赋予每一个跌倒的人都有再爬起来的勇气，
        要让每一个在生死边缘挣扎的人能保留有微笑面对命运的信心。

                                        艾柏鲁斯 于 毁灭之日後
C_WORD
        ]));
   reset();
}

void init()
{
        add_action("revive_player","pray") ;
}

int revive_player(string str)
{
    object player;

    player = this_player();
    if( str && member_group(geteuid(player), "admin") ) {
        player = find_player(str);
        if( !player )
                return notify_fail("没有这个人!\n");
        if( !player->query("ghost") ) 
                return notify_fail( player->query("c_name")+
                        " 现在是活生生的人!\n" );
        tell_object( this_player(), 
          "\n你使用你无上的法力，一阵奇迹似的光芒拢罩著"+
          player->query("short")+"。\n"
        );
        tell_object( player, 
          "万能的神 "+this_player()->query("c_name")+" 使用他无上的法力"+
          "，一阵奇迹似的光芒拢罩著你。\n"
        );
        tell_room( this_object(), 
          "万能的神 "+this_player()->query("c_name")+" 使用他无上的法力"+
          "，一阵奇迹似的光芒拢罩著"+player->query("short")+"。\n" , 
          ({ player, this_player() })
        );
        player->set_temp("skip_dead",1);
    }
        else if(!player->query("ghost")) {
                write("你伫立在英雄们的铜像前祈祷，希望能成为他们的一份子。\n");
                player->save_me();
                "/adm/daemons/backup"->user_backup(player);
                return 1;
        }
        else if( player->query_temp("skip_dead") )
          player->revive(1);
        else
          player->revive();
        return 1;
}
