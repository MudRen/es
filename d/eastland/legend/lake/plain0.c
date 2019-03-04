#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "plain0", "小径" );
    set_long(@C_LONG
你来到了一条清幽小径,小径的两旁有一排排不知名的树木,树枝挡住了阳光,
显得有些阴凉,树上一些鸟儿正啾啾地叫著。 在你旁边还有一棵参天的红桧木,树
干约需要五十个人合抱的宽度,真是一棵千年神木!你不禁地抬头一望,由然地生出
了憬仰之心。
C_LONG
    );
    set( "light",1);
    set( "exits", ([
     "up":LAKE"mountain8",
     "east":LAKE"plain1"
    ]) );
    set( "c_item_desc", ([
     "tree" : @C_LONG
这是一棵千年神木，如果你累了，或许可以倚在树干旁睡个觉(sleep)。
C_LONG
    ]) );
    reset();
}
void init()
{
   add_action("do_sleep","sleep");
}
int do_sleep(string arg)
{
   tell_object(this_player(),
      "你坐在地上倚著神木小憩一番....\n");
   this_player()->set_temp("block_command",1);
   call_out("back",7,this_player());   
   return 1;    
}   
void back(object player)
{
   player->delete_temp("block_command");
   tell_object(player,"咦，你醒来时居然身处在一个树洞里...\n");
   player->move(LAKE"tree1","SNEAK");
}