#include "../iigima.h"

inherit MONSTER ;
void create ()
{
        ::create();
        set_level(5);
        set_name("Young man Pan","青年潘恩" );
        add ("id", ({"drow", "pan","man" }) );
        set_short( "青年潘恩" );
        set("unit","位");
        set_long(
@C_LONG
这位勇敢的青年最近因为女朋友蒂德(Teeder)被神官送往神坛活祭而
伤心愈绝，他手上拿著一把锋利的短剑，誓言要救出自己的爱人。
C_LONG
        );
        set ("gender", "male");
        set( "no_attack", 1 );
     set( "chat_chance", 16 );
        set( "chat_output", ({
               "潘恩激动的说道: 我一定要救出蒂德!\n",
               "潘恩紧握著小刀，神情紧张地跺步著.....\n"
                       }));
        set( "inquiry", ([
         "teeder" : ({ "蒂德是我的女朋友啦~那个可恶的神官竟然将我的蒂德抓去活祭..呜\n"
                    })
                          ]) );
   wield_weapon("/d/deathland/weapon/dagger01");
}
