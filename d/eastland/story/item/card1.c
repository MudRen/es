// By Player@Eastern.Stories 1996

#include <mudlib.h>
#include <body.h>

inherit COINVALUE;
inherit OBJECT;

string book_color();

void create()
{       
	set_name("balance_amulet","进财符" );
        add("id",({"amulet"}));
	set_short("进财符");
	set_long(@LONG
一张大红色的符□，上面印著泥金四个大字『招财进宝』。你可以尝试去使用这张
符□，不知道会有什麽事情发生。(use balance_amulet)。
LONG);
	set("unit","张");
}

void init()
{
        add_action("do_balance","use");
}

int fil_ppl(object obj)
{ 
  object me;
  if (wizardp(obj)) return 0;
  if (userp(obj)&& obj->query_level()>8) return 1;
  return 0;
}

void second_msg(object me,object ob)
{
  int i,j,total=0;
  string *types;
  object *here;
  mapping money;
  if ( !interactive(me)) {
    ob->remove();
  }
  tell_room(environment(me),sprintf("%s%s%s%s%s%s",
    set_color("\n一阵狂风把所有人身上的钱币都卷到天上....\n","HIB"),
    set_color("白金币    ","HIW"),set_color("金币    ","HIY"),
    set_color("银币    ","CYAN"),set_color("铜币    ","YEL"),
    set_color("满天飞舞，然後就全部消失不见了...........\n\n","HIB"))
    );
  here = filter_array(all_inventory(environment(me)),"fil_ppl",this_object());
  for(i=0;i<sizeof(here);i++) {
    money = here[i]->query("wealth");
    if( !money ) money = ([]);
    types = keys(money);
    for( j=0; j<sizeof(types); j++ )
      total += money[types[j]] * coinvalue( types[j] );
  }
  total = (total / (sizeof(here)))/10;
  for(i=0;i<sizeof(here);i++) {
    here[i]->delete("wealth");
    here[i]->set("wealth/silver",total);
  }  
  me->delete_temp("block_command");
  ob->remove();
}

int do_balance(string arg)
{
  object ob;
  
  if (!arg||arg!="balance_amulet")
    return 0;
  if (!(ob=present(arg,this_player())))
    return 0;
  if (this_player()->query_level() < 9 ) {
    tell_object(this_player(),"你因为能力不足而无法使用这样物品。\n");
    return 1;
  }
    
  tell_object(this_player(),set_color(
    "\n你轻轻地把符□撕了开来，只见五彩祥云簇拥，天放异光罩住这里的每一个人..\n\n","HIY")
    );
      
  tell_room(environment(this_player()),set_color(sprintf(
    "\n%s你轻轻地把符□撕了开来，只见五彩祥云簇拥，天放异光罩住这里的每一个人..\n\n",
    this_player()->query("c_name")),"HIY"),this_player());
  this_player()->set_temp("block_command",1);     
  call_out("second_msg",3,this_player(),ob);
  return 1;
}

