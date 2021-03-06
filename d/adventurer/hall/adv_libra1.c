//#pragma save_binary

#include <mudlib.h>
#define MOB_INFO "/d/adventurer/mob_info/"
#define LAST_PAGE 10
#define TMP_FILE "/tmp/adv_note."+getoid(this_player())
#define NOTE_FILE "/d/adventurer/data/note.txt"

inherit ROOM;
inherit DOORS;

int process();
void create()
{
	object shelter;
	::create();
        set_short("冒险者资料室");
	set_long( @C_LONG_DESCRIPTION
这里是冒险者专属的资料室，墙上挂著许许多多的地图与留言板，房间的中间
是一张非常大的写字台，写字台上放著一本「旅行者手札」(note)  以及一本图鉴
(book)。许多冒险者围在写字台旁交头接耳，不知在讨论些什麽?
C_LONG_DESCRIPTION
	);

	set( "item_desc", ([ 
		"book" : @LONG_BOOK
这本「生物图鉴」是一位叫做塔卡达的冒险家穷其一生所撰的心血结晶，图鉴中记
载了王国内绝大部份的生物能力与简介，某些生物极其罕见，某些则数量奇多，但
它们往往都成功的将恐惧深植人们心底。当冒险者们不小心遇上它们，经常伴随著
恐怖且突然的死亡，但若是事前对该生物有所认识，就可以避免不幸的发生。在阅
读之前，你可以先打开书，看看(read)这本书的索引(index)。
LONG_BOOK
,               "note" : @LONG_NOTE
这本「旅行者手札」记载了旅行者们在旅途中所见所闻，其中有些是真实的，也有
一些只是谣言及不切实际的幻想。但只有有经验且聪明的旅行者才能分辩其真伪。
你可以使用read指令来看看上面记载的内容，也可以用write 把自己所见所闻记载
上去，但据说这本书是耶拉曼国王最喜欢的休闲读物，在上面灌水的人将会受到皇
室严厉的处罚。
LONG_NOTE
 ]) );
 	set("light",1);
        set( "exits", ([
             "north" : "/d/adventurer/hall/office",
             "west" : "/d/adventurer/hall/adv_shop",
             "northeast" : "/d/adventurer/hall/adv_guild"
               ]) );
        
        set( "objects", ([
              "avery" : "/d/adventurer/hall/monsters/avery"
               ]) );
         shelter = new("/d/adventurer/hall/obj/shelter");
                 shelter->move(this_object());
         set( "pre_exit_func", ([
              "west" : "check_flag"
               ]));
        create_door("north","south",([
               "keyword":({"woodendoor","door"}),
               "status":"closed",
               "c_desc":"一个小小的木门",
               "c_name":"小木门",
               "name":"small wooden door",
               "desc":"a small wooden door",
                                ]) );
        set("book_status","close");
        set("book_page",0);       
        reset();
}

void init()
{
     add_action( "do_read", "read" ) ;
     add_action("to_open","open");
     add_action("to_close","close");
     add_action("to_turn","turn");
     add_action("write_note","write");
}
int to_open(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
    can_look=query("book_status");
    if ( can_look=="open" ) 
      write("这书已经被打开了。\n");
    else {
      set("book_status","open");
      write("你打开这本生物图鉴。\n");
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
      write("你合上这本生物图鉴。\n");
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
int do_read( string str )
{

	if( !str || str=="" ) {
	    write("你要读什麽？\n");
	    return 1;
	    }
	if( str=="index" ) {
	    this_player()->more( MOB_INFO"c_list",0,1);
	    return 1;
	    }
	if( str=="note" ) {
	    this_player()->more(NOTE_FILE,0,1);
	    return 1;
	    }    
	if ( (string)query("book_status")=="close" ) {
	    write("请先打开书.\n");
	    return 1;
	    }
	  if ( file_exists(MOB_INFO"c_page" + query("book_page") ) ){
		this_player()->more( MOB_INFO"c_page" + query("book_page"),0,1);
		return 1;
          } else {
                cat( MOB_INFO"c_no_page") ;
                return 1;
          }          		
}
int write_note(string str)
{
	if (!str) return notify_fail("你要写那里啊?\n");
	if (str != "note") return notify_fail("不要乱画喔... \n");
    write("请不要在此讨论quest或灌水....\n");
    write("开始输入文字....\n");
	this_player()->edit(TMP_FILE, "process", this_object());
	return 1;
}
 
int process()
{
    string text, title;
    seteuid(getuid());
    text = read_file(TMP_FILE);
    rm(TMP_FILE);
    title = (string)this_player()->query("c_name")+" 於 "+
        "/adm/daemons/weather_d"->query_c_game_time()+" 写下:\n";
    write_file(NOTE_FILE, title+text+"\n");
    write("Ok.\n");
	return 1;
}
int check_flag()
{
      if ( wizardp(this_player()) || !present("avery")) return 0;
      if ((string)this_player()->query("class") != "adventurer" ) {
        tell_object( this_player(),
        "艾佛瑞说道: 那边只有冒险者能进去...\n");
        return 1;
       }
       else return 0;                
} 

int clean_up() { return 0; }
