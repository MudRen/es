#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("渔村道路");
        set_long( 
@LONG
你正走在渔村的道路上，迎面扑来的是一股浓浓的腥臭味；在地上，纵横交错
著血水枯乾的小河；一团团苍蝇，正汲汲於腐烂的鱼肉上，不时发出嗡嗡地鸣声。
晦暗不明的天空，乌云团簇好似一只只正在张牙舞爪的野兽，野兽正恶狠狠地瞪著
你，好像对著你说：『快来吧，快来吧，我的食物』。道路往东、南边延申；北边
有间矮矮的房子；西边是一块空地。
LONG);
    set( "light",1);
    set( "exits", ([
         "east":LAKE"village13",
        "south":LAKE"village11"
    ]) );
    ::reset();
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
  object player;
  if ( !arg || arg!="house" )
       return notify_fail("你要进入那里?\n");
  player=this_player();
  tell_room( this_object(),
      sprintf("%s走进屋子内。\n", player->query("c_name") ), player );
  player->move_player(LAKE"house12","SNEAK");
  tell_room( environment(player),
      sprintf("%s(%s)走了进来。\n", player->query("c_name"),player->query("name"
      ) ), player );
   return 1;
 }