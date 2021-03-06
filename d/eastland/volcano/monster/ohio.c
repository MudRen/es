#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(8);
	set_name( "Ohio", "俄亥俄" );
	set_short( "俄亥俄" );
	set_long( 
             @LONG
你看他走来走去，不时的跺脚，满头大汗的样子, 不禁想要帮助他。
LONG
	);
	set( "alignment", 200 );
        set( "gender", "male" );
        set( "race", "human" );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 17 );
	set_perm_stat( "piety", 7 );
	set_perm_stat( "karma", 10 );
	set ("max_hp", 220);
	set ("hit_points", 220);
	set ("wealth", ([ "gold": 5 ]) );
	set("natural_armor_class",30);
	set("natural_defense_bonus",8);
        set_natural_weapon(3,5,5);
    set ("exp_reward",690 );
    set ("chat_chance", 10);
    set ("chat_output", ({
      "俄亥俄说：有那位好心人可以帮助我吗？\n",
    }) );
}

void init()
{
 add_action( "to_help", "help" );
}

int to_help(string str)
{
   int i;
   object player,ob1,*items;
   if(!str || str != "ohio") {
     write(
           "帮助谁?\n");
     return 1;
   }
   items=all_inventory(this_player());
   for(i=0;i<sizeof(items);i++)
     if ((string)items[i]->query("name")=="ohio ring")
     {  tell_object(this_player(),
        "俄亥俄说：你找到我的兄弟了吗？\n");
        return 1;
     }
   write( 
     "\n俄亥俄说: 可以帮助我找我的兄弟吗？我们两兄弟进入火山地区探险，\n" 
     "在途中某个晚上，我在睡梦中突然听到一声惨叫，起来一看，我兄弟已\n"
     "已经失踪了。第二天早上，我也赶紧收拾东西在这附近找寻我弟弟的下\n"
     "落，找著找著，竟然遇到了一个凶恶的土人，好在我跑得快，不然一定\n"
     "没命了，我猜我弟弟大概被他们抓走了，能不能请你帮我找他，谢谢。\n"
   );
if ( !this_object()->query_temp("gived") ) {
   write("请将这个戒指交给他，他就会知道我还活著。\n");
   ob1 = new( OOBJ"ohio_ring" );
   ob1->move(this_object());
   set_temp("gived",1);
   command("give ring to "+lower_case((string)this_player()->query("name")));
   this_player()->set_temp("ohio",1);
} else 
	write("可惜我刚刚把我的戒指交给一个愿意帮我的人，否则你就可以拿它当信物了。\n");
   return 1;
}

int accept_item(object me, object item)
{
	string name;
        
        name=(string)item->query("name");
        if ( !name || !(name=="oregon ring")) {
        return 0;
        }

    if (!item->query(me->query("name"))) {
      tell_object(me,
        "俄亥俄说：你这个戒指是从别人那里摸来的吧!\n");
      return 1;
    }

    tell_object( me, 
      "俄亥俄说：啊! 这是我兄弟的戒指。\n"
      "俄亥俄向"+me->query("c_cap_name")+"拜倒，说道: 谢谢你救我的兄弟出来！\n"
      "我也要继续我的旅程了，再见。\n"
    );
    command("wave "+lower_case((string)this_player()->query("name")));
    if( !me->query_quest_level("Ohio's_brother") ) {
      me->finish_quest("Ohio's_brother",1);
      if ((string)me->query("class")=="scholar") {
        tell_object(me,set_color("俄亥俄又匆匆忙忙的跑回来：这个东西是我在旅行的时後得到的，就送给你吧，说著就往\n你的手里一塞，就离开了。你摊开手一看，是一个桃花木盒，一打开，一只木精灵跳了出\n来，说道：我的主人，我能运用一些大自然的力量来帮助你，有需要请召唤我。\n","HIG"));
        me->set("demand/wood",2);
      }
      tell_object( me,
         set_color("[你完成了 Ohio 任务，得到 5000 点经验]\n","HIY"));
      me->gain_experience(5000);
    }
    item->remove();
    this_object()->remove();
    return 1;
}
