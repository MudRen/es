#include <mudlib.h>
#include "camp.h"
inherit ROOM;

int apply_wall ; // 表示已经上墨
int apply ;      // 表示 apply 可用於此
int papermob ;     

void create()
{
	::create();
	set( "clean", 0);
        apply = 1 ; 
	set( "apply",1) ;
	apply_wall = 0 ;
	set( "apply_wall",0) ;
        papermob = 0 ;
	
    set_short( "石室" );
	set_long( @C_TOPIC
这间石室空空汤汤的，而且光线又不太充足，角落处好像有什麽在动，石室
正前方壁上(wall)，则划满了一堆奇怪的古文。你上前仔细看看，不禁讶异是何
人以指力刻划留下的。旁边地上放了个箱子(box)，看来以很久没人动过了。
C_TOPIC
);

	set( "search_desc", ([
	  "box"   : "@@search_box",
            "here" :  "@@search_here",
	]) );

	set( "item_func", ([ 
	                      "box"   : "msg_box",
	                      "wall"  : "msg_wall",  ]) );

	set( "exits", ([ "up" : CAMP"camp7" , "west" : CAMP"camp9" ]) );

        set("objects",([
           "cat#1" : CAMPMOB"cat", 
           "cat#2" : CAMPMOB"cat", 
           "rat" : CAMPMOB"rat", 
        ]) ) ;

	reset();
}

string search_box()
{
    object ob;
    if( this_object()->query("clean") ) return 0;
    ob = new( CAMPOBJ"bstone" );
    ob->move(this_object());
    this_object()->set( "clean", 1 );
    return "你打开箱子，结果掉出了一块黑色石头。\n"; 
}

string search_here()
{
    object ob;
    if ((papermob) || present("sheet",this_object()) ) return
      "你找了老半天，并没有找到什麽东西!!\n" ; 
    else {
      ob = new( CAMPMOB"paper_mob" );
      ob->move(this_object());
      papermob = 1 ;
      return "突然间好像什麽一个白衣长发的东西飘了过去，你不禁吓出一身冷汗。\n"; 
    }
}

int msg_box()
{
    write("尘封的木箱，看来毫不起眼，还沾了些墨似的。\n"
    );         
    return 1;
}

int msg_wall()
{
  if (!apply_wall) {
  write("这片石壁上刻满了奇怪的文字，也许\是武林秘笈喔，想办法拓印下来吧。\n" );
  } else {
  write("石壁上刻满了奇怪的文字，而且已经上墨了，也许\会乾掉吧!!\n") ;  
  }
  return 1;
}

void to_find_wall( string arg )
{
  write(
    "你用黑色石头将石壁上文字都涂上一遍，累的满身大汗。\n"
  );
//  this_player()->set_explore("noden#9");
  apply_wall = 1;
  set( "apply_wall", 1);
  call_out("ink_no",200) ;
}

void ink_no()
{
  set( "apply_wall", 0);
  apply_wall=0 ;
}

void reset()
{
    ::reset();
    set( "clean",0);
    apply_wall = 0 ;    
    set( "apply_wall",0) ;
   papermob = 0;
}
