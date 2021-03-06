//#pragma save_binary

#include <mudlib.h>
#define LAST_PAGE 5
#define AREA "/doc/area/area_"

inherit ROOM;

void create()
{
	::create();
	set_short( "冒险者之家" );
	set_long(@C_LONG
你现在正站在一间充满著祥和气氛的大厅之中，这个大厅是用某种白
中带著淡蓝色纹路的石材建成的，一些绿色的植物和漂亮的花卉装饰著大
厅四周的圆柱。四面的墙壁上雕刻著极为优美的图画。而大厅的中央有著
一本很大的书本( book )置於其中。北方有个通道, 可以通向任务殿堂。
C_LONG
	);
	
	set("item_func", ([
	    "book":"area_book",
	]) );
	
	set( "light", 1 );
	
	set( "exits", ([
		"north" : "/d/noden/farwind/quest_room",
	]) );
	
	set("book_status","close");
	set("book_page",0);
}

void init()
{
     add_action("to_open","open");
     add_action("to_close","close");
     add_action("to_read","read");
     add_action("to_turn","turn");
}

int area_book()
{
    write( 
    "探险\n"
     "一本记载著由许许多多冒险者所记录下的各个区域的书.\n"
    );
    return 1;
}

int to_open(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
    can_look=query("book_status");
    if ( can_look=="open" ) 
      write("这书已经被打开了.\n");
    else {
      set("book_status","open");
      write("你打开探险者之书.\n");
      }
    return 1;    
}

int to_close(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
    can_look=query("book_status");
    if ( can_look=="close" ) 
      write("这书已经被合上了.\n");
    else {
      set("book_status","close");
      set("book_page",0);
      write("你合上探险者之书.\n");
      }
    return 1;    
}

int to_turn(string str)
{
    mixed page;
    
    if (!str) return 0;
    else if ( str=="page" )
      {
          if ( (string)query("book_status")=="close" )
            return notify_fail("请先打开书.\n"); 
          page=(int)query("book_page")+1;
          page=(page==LAST_PAGE)?0:page;
          write("你把书翻到了第"+ page +"页.\n");
          set("book_page",page);
      }
    else if ( sscanf(str,"page to %d",page)==1 )
      {
         if ( (string)query("book_status")=="close" )
            return notify_fail("请先打开书.\n"); 
         write("你把书翻到了第"+ page +"页.\n");
         set("book_page",page);
      }
    else 
      write("翻书的方法如下:turn page or turn page to <num>.\n");
    return 1;  
}

int to_read(string str)
{
    if (!str||str!="book") return 0;
    if ( (string)query("book_status")=="close" )
            return notify_fail("请先打开书.\n"); 
    cat(AREA+query("book_page"));
    return 1;
}

