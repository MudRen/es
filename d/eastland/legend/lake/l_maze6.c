#include "/d/eastland/legend/legend.h"

inherit LAKE+"in_lake1";
int be_search,be_open;
void create()
{
        ::create();
    set_short("大海");
        set_long( 
@LONG
你划著船桨来到了海面上，极目四眺，是一片风平浪静的无垠大海，远处几艘
渔船正随著波浪载浮载沈，撒网成群，辛勤地捕著渔。波面上不时穿梭著飞鱼，阳
光反射其身上，好似一颗颗亮晶晶的银宝石。美中不足的是，在小船旁漂来些许垃
圾。
LONG
    );
   set("c_item_desc",([
      "垃圾":"一堆漂浮在水面上的垃圾 ( garbage ) 。\n"
   ]) );
   be_search=0;
   be_open=0;
    ::reset();
}
void init()
{
  ::init();
  add_action("do_search","search");
  add_action("do_open","open");
}
int do_search(string arg)
{

   if ( be_search ) return 0;
   if ( !arg || arg!="garbage" ) return 0;
   if ( !this_player()->query_temp("captain_asked") ) return 0;
   
   be_search=1;
   tell_object(this_player(),"你从垃圾堆中找到一个小瓶子(bottle)。\n");
   set("c_item_desc",([
      "bottle":"   一个玻璃子，你可以试著打开(open)它。\n"
   ]) );
   return 1;
}
int do_open(string arg)
{
    object fruit;
    if (!arg || arg!="bottle") return 0;
    if (!be_search) return 0;
    if (be_open) return 0;
        be_open=1;
    tell_object(this_player(),
       "你打开小瓶子，忽见一个婀娜多姿的人形从瓶子里面跑了出来．．\n");
    tell_object(this_player(),@C_LONG
「少女小渔」的魂魄说道：妾身乃是多年前死於大浪的渔村村长的未婚妻，因闾王
          感思念之深，特来与君相见。烦你覆村长说妾身永远记得和他在一起的
          时光，若有来世，愿与他再结连理。

「少女小渔」的魂魄有所感伤地消失了。   
C_LONG
    );
    this_player()->set_temp("wife_asked",1);
    delete("c_item_desc/bottle");
    call_out("back",300);
    return 1;
}
void back()
{
   be_search=0;
   be_open=0;
}
void reset()
{
    be_search=0;
    be_open=0;
    delete("c_item_desc/bottle");
    ::reset();
}
