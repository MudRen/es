#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(3);
	set_name( "dying man", "濒临死亡的人" );
	set_short( "濒临死亡的人" );
        add("id",({"man"}));
	set_long( 
             @LONG
你看他倒在地上□□一息的样子，想救他又恨自己没这个能力，他能活到现在，完全
是为了要把一个秘密(secret)讲出来。
LONG
	);
	set( "alignment", 200 );
        set( "gender", "male" );
        set( "race", "human" );
        set("hit_points",1);
        set("no_attack",1);
        set ("chat_chance", 5);
        set ("chat_output", ({
             "你听到那快死的人说：快，把耳朵靠过来，我支持不下去了\n"
             }) );
        set ( "inquiry", ([
              "secret" : "@@ask_secret",
              ]) );
        call_out("disappear",100);
}

void disappear()
{
  tell_room(environment(),"这濒临死亡的人化成一缕\白烟向天飘去。\n");
  remove();
}

void ask_secret(object who)
{
  if (this_player()->query_temp("ohio")<2) {
    tell_object(who,
      "濒临死亡的人说：你假如对别人仁慈，我也会对你仁慈。\n");
  }
  else {
    tell_object(who,
      "濒临死亡的人说：想要救人的话，就去摸山顶那个图案。\n");
   }
   tell_room(environment(),"他终於□下了最後一口气，你看到□体化成一丝白烟向天飘去。\n");
   this_object()->remove();
   return;
}
