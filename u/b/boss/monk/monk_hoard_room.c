#include <mudlib.h>

#define TMP_FILE "/tmp/monk.paper."+getoid(this_player())
#define WALL_FILE "/d/monk/doc/wall.txt"
#define MONK_PAGE "/d/monk/doc/monk_info/"
#define LAST_PAGE 10

inherit ROOM;

void create()
{
  object yuu;
  ::create();
  set_short("Monk's history room", "少林寺功\德坊");
  set_long(
@C_LONG_DESCRIPTION
这□是记录少林武僧历代以来建立所立下的功\德的地方。偌大的空旷房间
左右两边都有名人排行榜(scroll)，你可以张大眼睛瞻仰瞻仰。房间的中央\摆\
著的据说是少林寺开派祖师爷--达摩--的雕像(statue)。由於传说中，只要你
诚心诚意抚摸它，功\力会大增，所以这座雕像已经模糊不堪了。
    你的眼光快速的扫瞄四周，在不显眼的墙角摆\著一张满是灰尘的□□米，
看来是前辈高僧们结跏趺坐的地方。□□米的上方有一卷纸画(paper),上面到
处都是断断续续的线条，你心里想著：难道是武功\心得所在?
C_LONG_DESCRIPTION
  );

  set ( "light", 1 );
  set ( "item_desc", ([
        "book" : @BOOK_LONG
        这本书的封面写著大大的几个字 : 少林武僧录
        
    这几个字看来龙飞凤舞的, 你心里想这里面记载的一定是十分有名的前辈的事迹。
让你很想将他翻开 (open) 来读 (read) ....... 

BOOK_LONG
      ]) );
  set ( "book_statue" , "close" );
  set ( "book_page" , 0 );
  set ( "item_func", ([
    "scroll" : "look",
    "paper"  : "look",
    "statue" : "look"
  ]) );
  set ( "exits", ([ 
    "west" : "/d/monk/guild/gonfu_room1"
  ]) );

    yuu = new("/d/monk/guild/monsters/taker");
    yuu->move(this_object());
	reset();
}

int clean_up() { return 0; }

void init()
{
  add_action ( "do_look", "look" );
//  add_action ( "do_open", "open" );
//  add_action ( "do_close", "close");
//  add_action ( "do_read", "read" );
//  add_action ( "do_turn", "turn" );
  add_action ( "do_write", "write" );
}

int do_open(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
        can_look=query("book_status");
    if ( can_look=="open" )
        write("这书已经被打开了。\n");
    else {
        set("book_status","open");
        write("你打开这本少林武僧录。\n");
    }
    return 1;
}

int do_close(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
        can_look=query("book_status");
    if ( can_look=="close" )
        write("这书已经被合上了.\n");
    else {
        set("book_status","close");
        set("book_page",0);
        write("你合上这本少林武僧录。\n");
    }
    return 1;
} 

int do_turn(string str)
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
    if ( (string)query("book_status")=="close" ) {
        write("请先打开书.\n");
        return 1;
    }             
    if ( file_exists(MONK_PAGE"c_page" + query("book_page") ) ){
        this_player()->more( MONK_PAGE"c_page" + query("book_page"),0,1);
        return 1;
    } else {
        cat( MONK_PAGE"c_no_page") ;
        return 1;
      }
}
int do_look ( string arg )
{
  object player;
  string name;
  int i;
  object *me;

  player = this_player();
  name =  player->query( "c_name" );
    
  if ( !arg ) return 0;
  else if ( arg == "paper" ) {
    this_player()->more (WALL_FILE);
    return 1;
  }
  else if ( arg == "statue" ) {
    tell_object ( player, @LONG
由於年代久远，眼前的达摩雕像，竟有八分像传说中的小天使--Angel,一位有史以来
就被武僧公会的小光头们传为神话的喵喵。当你再仔细左瞧右瞧，发现了另一个神话
人物的影子--ruby。也许\是她们两位的精神灌注在这个雕像中的关系吧?!
    这座达摩雕像正前方的桌子上放著一本书(book), 看起来还蛮新的。
LONG
  );
    tell_room (
      environment (player),
      name + "摸了摸眼前的达摩雕像，法喜充满心中。\n",
      player );
    return 1;
  }
  else if ( arg == "scroll" ) {
    me = users();
    for( i=0; i<sizeof(me); i++ )
      "/d/monk/guild/misc/topmonks"->log_player(me[i]);
    write (
      (string)find_object_or_load ( "/d/monk/guild/misc/topmonks")->get_list() );
    tell_object ( player, "你盯著排行榜看呀看的，心中越来越崇拜前人所立下的功\德\n" );
    tell_room (
      environment (player),
      name + "盯著排行榜看呀看的，满脸激动兴奋的表情。\n",
      player );
    return 1;
  }
  return 0;
}    

int do_write (string str)
{
  if (!str) return notify_fail ( "你要写那里啊?\n" );
  if ( str != "paper" ) return notify_fail("*** 这-里-是-功-德-坊 *** 严-禁-乱-涂 ***\n" );
  write("请开始输入文字 -->\n");
  this_player()->edit(TMP_FILE, "process", this_object());
  return 1;
}

int process()
{
  string text, title;

  text = read_file (TMP_FILE);
  rm (TMP_FILE);
  title = (string)this_player()->query("c_name")+" 於 "+
        "/adm/daemons/weather_d"->query_c_game_time()+" 写下:\n";
  write_file ( WALL_FILE, title+text+"\n" );
  write ( "你终於将心得写完了.\n" );
  return 1;
}
