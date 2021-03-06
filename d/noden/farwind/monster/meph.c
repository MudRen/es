#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level( 10 );
   set_name( "Meph", "婚纱店老板莫飞" );
   add( "id", ({ "owner", "boss" }) );
   set_short( "莫飞" );
	set_long(@C_LONG
    莫飞是一个年约三十的青年, 他在历经一场没有结局的苦恋後,
来到此地定居, 并开了此一结婚礼服店, 希望天下有情人均成眷属。
你可以问他如何租借(rent)礼服。
C_LONG
    	       );
	set( "no_attack", 1 );
	set( "gender", "male" );
   set( "inquiry", ([
         "rent" : 
@LONG
首先, 请您先看我们的价目表(menu),
您可以买断我们所提供之礼服; 但是如果您嫌贵的话, 可以在
完成婚礼後退回(return)给我, 除花, 戒指, 及护盾圆球外,
每件将退还您1500银币. 另外提醒您, 如果你不结婚, 戒指及
护盾圆球是不能戴上与储存的.
LONG
     ]) );
}

int accept_item(object who, object item)
{
   tell_room( environment(),
        "商店老板奸笑道: 谢了! 白痴!\n"
        "( 商店老板把"+item->query("c_name")+"收起来! )\n" );
   item->remove();
   return 1;
}

void init()
{
   add_action("do_buy", "buy");
   add_action("do_return", "return");
}

int do_buy(string str)
{
   object ring, globe;

   if( str == "ring" || str == "wedding ring" ) {
       if( present("wedding ring",this_player()) ) {
       printf( "老板说: 结婚戒指一个人只需要一只!\n" );
       return 1;
       }
       if( this_player()->query("wealth/silver")<5000 ) {
       printf( "老板说: 等你有足够的银币再来吧!\n" );
       return 1;
       }

       ring = new( "/d/noden/farwind/wedding_obj/wedding_ring" );

       printf( "你买下一只结婚戒指.\n" );
       ring->move(this_player());
       this_player()->credit("silver", -5000);
       return 1;
   }
   if( str == "globe" || str == "wedding globe" ) {
       if( present("wedding globe",this_player()) ) {
       printf( "老板说: 结婚护盾圆球一个人只需要一个!\n" );
       return 1;
       }
       if( this_player()->query("wealth/silver")<8000 ) {
       printf( "老板说: 等你有足够的银币再来吧!\n" );
       return 1;
       }

        globe = new( "/d/noden/farwind/wedding_obj/wedding_globe" );

       printf( "你买下一个结婚护盾圆球.\n" );
       globe->move(this_player());
       this_player()->credit("silver", -8000);
       return 1;
   }
   if( str != "ring" && str != "wedding ring" &&
       str != "globe" && str != "wedding globe" &&
       this_player()->query("spouse") ) {
   printf( "老板怒道: 你想重婚吗?\n" );
   return 1;
   }
}

int do_return(string str)
{
   object player, obj;
   string armor;

   player = this_player();

   if( !str || str =="" ) return notify_fail( "你要还什麽东西?\n" );

   if ( sscanf(str, "%s", armor)==1 ) {
     obj = present(armor,player);

   if( !obj ) return notify_fail( "你没有这东西!\n" );
   if( !obj->query("wedding_obj") )
      return notify_fail( "莫飞说: 对不起! 这件东西本店不回收!\n" );
   if( !this_player()->query("spouse") )
      return notify_fail( "莫飞说: 你还没结婚啊! 先留著它吧!\n" );
   tell_room( environment(),
        "莫飞说: 退回押金1500银币, 谢谢惠顾.\n"
         "( 莫飞把"+obj->query("short")+"收起来等待清洗 )\n" );
   player->credit("silver", 1500);
   obj->remove();
   return 1;
   }
}
