#include "../story.h"

inherit ROOM;
int have_head=1;
void create()
{
        ::create();
	set_short("解池");
	set_long(@LONG
异於前面所走过的洞穴，你发现这里的空气非常乾燥，并且温暖极了！相传当
年黄帝大战蚩尤，蚩尤打了个败仗因此被砍下头颅，身首异处，一分为二，其中一
部份被丢在这里。解池又叫盐池，池里的盐水呈红色，人们都说那是蚩尤的血流积
而成的。在解池旁有一个坟墓，当年黄帝怕蚩尤死後作怪，因此在这里修了个坟墓
加了某种禁咒，并在来这里的途中设下几只镇守这里的怪物，以防被盗。
LONG
	);
        set( "exit_suppress", ({
          "su"}) );
	set("exits", ([
          "southup" : SAREA"spell3",
               "su" : SAREA"spell3"
        ]) );
	reset();
}
void init()
{
   add_action("do_auction","auction");
   add_action("do_search","search");
}
int do_search(string arg)
{
   object head; 
   if ( !have_head ) return 0;
   have_head=0;
   write("你找了找，发现旁边坟墓里埋了一具□体！");
   if ( ( this_player()->query_perm_stat("str") ) < 10 ) {
     write("可惜你力量不够，无法把它挖起来。\n");
     return 1;
   }
   write("於是你把它挖起来。\n");
   head=new(SITEM"head1");
   head->move(this_object());
   call_out("recover",900);
   return 1;
}
void recover()
{
   have_head=1;
}
int do_auction(string arg)
{
   write("\n这里忽然起了阵咒语，令你无法专注於拍卖动作！\n\n");
   return 1;
}
