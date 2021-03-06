#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short( "井中");
	set_long( 
@LONG_DESCRIPTION
你正坐在大桶子里，井壁上长了一些青苔，从这里往上看去，天空只剩下一点点，
看来想出去只有叫人帮忙了；往水中看去，似乎有淡淡的亮光在水底下，不知道可不
可以潜下去瞧瞧。
LONG_DESCRIPTION
	);
set("search_desc", ([
    "here":"@@to_search_here" ]) );
reset();
}

string to_search_here()
{
  string str;

  str="\n你在这儿仔细的搜索了一遍，没有发现任何通路，正不知道如何出去时，\n"
       +"突然想起了很久以前上课学过的摩斯求救密码\n\n";
  return str;
}

void init()
{
  add_action("do_sos","sos");
  add_action("do_dive","dive");
}

int do_sos()
{
  object ob;

  ob=new(OOBJ"g_chocolate"); /* stupid method to init the room above well*/
  write("你在井壁上敲著摩斯密码．．．－－－．．．\n");
  ob->move(OGROUP"warea10");
  ob->remove();
  if(present("well guard",find_object(OGROUP"warea10"))) {
     write("守卫探头看著你：叫你不要自杀你就偏不听。\n");
     write("守卫说：接住绳子，我拉你上来。\n\n");
     tell_room(this_object(),"你见到"+this_player()->query("c_name")+"被一根绳子慢慢的拉了上去。\n",this_player());
     this_player()->move_player(OGROUP"warea10","SNEAK");
     return 1;
  }

  write("\n天空传来老猫的声音：对不起，能帮助你的人已经被Ｋ死了。\n");
  return 1;
}

int do_dive()
{
  if (this_player()->query_skill("swimming")<50) {
    write("你的泳技似乎还不足以让你潜入水中。\n");
    return 1;
  }
  if (random ( (int)this_player()->query_skill("swimming")) < 50) {
    write("你想以自己的泳技，潜水是不会有啥问题的，於是就跳了下去。\n");
    write("才游了几下，就发现好像气不够了，只好又回到水面。\n\n");
    tell_room(this_object(),"你见到"+this_player()->query("c_name")+ "跳下水去，不一会儿，气喘如牛的慢慢爬进木桶子里。\n",this_player());
    return 1;
  }
  write("你仗著你的泳技精湛，吸了一大口气之後，就不顾一切的跳入水中。\n");
  tell_room(this_object(),this_player()->query("c_name")+"跳下水去，溅起一大片水花，你的身上到处都是小水珠。\n",this_player());
  this_player()->move_player(OTEMP"well2","SNEAK");
  return 1;
}
