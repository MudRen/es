#include <mudlib.h>

inherit MONSTER;

void create()
{
   ::create();
    set_level(10);
    set_name( "Morish Dio" , "摩理斯 迪奥" );
    add( "id", ({ "dio","morish","vendor","seller" }) );
    set_short( "摩理斯 迪奥" );
    set_long(@CLONG
摩理斯  迪奥曾经是一位出色的冒险者，但是在他经历过许多次差点    
致命的危机後，他对金钱的兴趣，渐渐取代了他原先对冒险的热情。
虽然如此，他仍是不舍离去他过去最爱的冒险活动，因此他决定在此
投资开设冒险工具专卖店，一方面以此帮助後进，另一方面也可以此
累积财富。
你可以问他有关 price的事，相信他一定乐於帮助你的。
CLONG
    );
    set( "gender", "male" );
    set( "inquiry" , ([
    "price" : "@@ask_price"
    ]) );
}
void ask_price()
{
write(
"摩理斯 迪奥说道: menu 就贴在墙上，你可以去参考看看\n"
"如果你会搭营帐的话，这里也可以买营帐喔....\n");
}

int accept_item(object who, object item)
{
   tell_room( environment(),
        "摩理斯 迪奥奸笑道: 谢了! 白痴!\n"
        "( 摩理斯 迪奥把"+item->query("c_name")+"收起来! )\n" );
   item->remove();
   return 1;
}

void init()
{
   npc::init();
   add_action("do_buy", "buy");
}

int do_buy(string str)
{
   object *who,tool,me;
   int loop,num,i;
   string *file_name;

   me = this_object();
   num = 3000*( 2 - (int)this_player()->query_skill("trading")/70);
   if( str == "tool" || str == "camp" ) {
       who = (object *)me->query("who_buy_camp");
//       for (loop=0;loop<sizeof(who);loop++) {
//       if (who[loop]->query("name") == this_player()->query("name")) {
//       printf( "老板说: 一个人只能买一个帐蓬!\n" );
//       command( "kick "+this_player()->query("name"));
//       this_player()->receive_damage(10);
//       return 1;
//      }
//       continue ;
//      }
       if( present("camp tools",this_player())) {
       printf( "老板说: 你已经有一个了!\n" );
       command( "kick "+this_player()->query("name"));
       this_player()->receive_damage(10);
       return 1;
       }
       if( this_player()->query("wealth/silver")<num ) {
       printf( "老板说: 等你有足够的银币再来吧!\n" );
       return 1;
       }
       if( !this_player()->query_skill("camp") ) {
       printf( "老板说: 你不会扎营，卖给你也是浪费...\n" );
       return 1;
       }
       tool = new( "/obj/camp_tool" );

       printf( "你买下一包帐蓬工具\n" );
       if ( !this_object()->query("who_buy_camp") || 
       this_object()->query("who_buy_camp")=="") {
            file_name = get_dir("/d/adventurer/hall/camp/");
            for( i=0; i<sizeof(file_name); i++ )
            rm("/d/adventurer/hall/camp/" + file_name[i]);
            }
       this_object()->add("who_buy_camp", ({ this_player() }) ) ;                           
       tool->move(this_player());
       this_player()->debit("silver", num);
       this_object()->credit("silver", num);
       return 1;
       }
       return 0;
}
void announce( string c_msg )
{
    object *usr;
    int i;
                
    usr = users();
    for( i=0; i<sizeof(usr); i++ ) {
    if( !environment(usr[i]) ) continue;
    tell_object( usr[i], c_msg);
    }
}
void die()
{
   object killer;
   mapping bank;
   killer = query("last_attacker");
   if( !killer ) {
   ::die();
   return;
   }
   bank = killer->query("bank_balance");
   if( !bank ) bank = ([]);
   killer->set("bank_balance",([]));
   announce(
     "\n"+killer->query("c_name")+"给了摩理斯 迪奥致命的最後一击....\n"
     "摩理斯 迪奥痛苦的大叫: 我亲爱的朋友们，一定要帮我报仇....\n\n"
     "税务官毕卡博，牛万金和希露芙齐声高喊: 可恶的"+killer->query("c_name")+"\n"
     "你一定会因此付出惨痛的代价的。\n\n");
   ::die();
  }
