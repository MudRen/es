#include <mudlib.h>

#define TMP_FILE "/tmp/monk.paper."+getoid(this_player())
#define WALL_FILE "/d/monk/doc/wall.txt"

inherit ROOM;

void create()
{
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
  set ( "item_func", ([
    "scroll" : "look",
    "paper"  : "look",
    "statue" : "look"
  ]) );
  set ( "exits", ([ 
    "west" : "/d/monk/guild/gonfu_room1"
  ]) );

  set( "objects", ([
    // "list"    : MATE"/daemons/list",
//    "mayumei" : MATE"/monster/toy_girl",
    "yuu"     : "/d/monk/guild/monsters/taker" ]) );
	reset();
}

int clean_up() { return 0; }

void init()
{
  add_action ( "do_look", "look" );
  add_action ( "do_touch", "touch" );
  add_action ( "do_brood", "brood" );
  add_action ( "do_write", "write" );
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
    你一发现这事实，忍不住心中的冲动想去摸摸(touch)这个雕像(statue)。
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
  else if ( arg == "tatami" ) {
    tell_object ( player,
      "你把注意力集中在□□米上面，心里想著:\n" +
      "  也许\在上面打坐(brood) 可以感召到前辈们的精神!!\n");
    tell_room (
      environment (player),
      name + "盯著满是灰尘的□□米看呀看的，不会是想睡一觉吧?!\n",
      player );
    return 1;
  }
  return 0;
}    

int do_touch ( string arg )
{
  object player;
  string name;

  player = this_player();
  name =  player->query( "c_name" );
    
  if( !arg || arg != "statue" ) {
    tell_object ( player, "这是什麽地方你知道吗? 不要随处乱摸!!\n");
    tell_room (
      environment (player),
      name + "鬼鬼祟祟的在这儿乱摸，不知想干什麽。\n",
      player );
    return 1;
  }
  tell_object ( player, 
    "  你恭恭敬敬地摸了达摩尊者的雕像，突然醒悟到:\n" +
    "啊! 原来更加勤奋的念经、超渡、学武才是武僧之道啊!!\n" +
    "  於是你把眼光放到墙角的□□米(tatami)，看它陈旧的\n" +
    "样子，大概是前辈们结□打坐的地方吧!!\n"
  );
  tell_room (
    environment (player),
    name+"恭敬地在达摩尊者的雕像上摸了摸，似乎领悟到至理而发出会心一笑 ^_^\n" +
    name+"的眼光集中在放置在墙角的□□米上面。\n",
    player );
  return 1;
}

int do_brood (string arg)
{
  object me;

  me = this_player();
  if ( (int)me->query_temp ( "brood_flag" ) == 1 ) {
    tell_object ( me, "常常去找先圣先贤会被敲脑袋哦，等一下再入定参禅吧!!\n");
    return 1;
  }
  if ( !arg || arg != "tatami" ) {
    tell_object ( me, "随处乱打坐怎麽对得起先圣先贤?\n");
    return 1;
  }
  tell_object ( me, "你静下心来在□□米上结□, 思想逐渐空明, 进入忘我无我之境...\n");
  tell_room ( environment (me), "你发现"+
    me->query ( "c_name" )+"不管三七二十一, 坐在□□米上面好像雕像一般。\n",
    me);
  me->set_temp ( "block_command", 1 );
  call_out ( "result", 2+random(2), me, 4+random(7), this_object() );
  return 1;
}

void result (object me, int count, object place)
{
  string mtd;
  int fp, max;
  int level, alignment, monk_score;
  int enough;

  fp = (int)me->query ( "force_points" );
  max = (int)me->query ( "max_fp" );
  level = (int)me->query_level ( );
  alignment = (int)me->query ( "alignment" );
  monk_score = (int)me->query ( "monk_score" );
  // tell_object ( me, "[Info from mate] level : "
  //   + level + " alignment : " + alignment + " monk_score : " + monk_score + "\n" );
  if ( level >= 15 && alignment >= 5000 && monk_score >= 1000 )
    enough = 1;
  else
    enough = 0;
  if ( count > 0 && fp < max ) {
    fp = fp + 8 + random (max/30);
    if ( fp > max ) fp = max;
    tell_object ( me, "..................................\n" );
    if ( enough == 1 ) me->set ( "force_points", fp );
    count--;
    call_out ( "result", 2+random(2), me, count, place );
    return ;
  }
  me->delete_temp ( "block_command" );
  tell_object ( me, "一阵沉思之後, 你的思想逐渐爽朗, 慢慢回到了现实。\n" );
  tell_room ( place,
    me->query ( "c_name" )+"满脸灰尘地从□□米上站了起来。\n",
    me
  );
  me->set_temp ( "brood_flag", 1 );
  call_out ( "reset_brood", 200, me );
  return ;
}

int reset_brood (object me)
{
  if (me) {
    tell_object ( me, "你发现自己在先圣先贤们的思路中，渐行渐远....\n" );
    me->delete_temp ( "brood_flag" );
  }
  return 1;
    
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

  // seteuid(getuid());
  text = read_file (TMP_FILE);
  rm (TMP_FILE);
  title = (string)this_player()->query("c_name")+" 於 "+
        "/adm/daemons/weather_d"->query_c_game_time()+" 写下:\n";
  write_file ( WALL_FILE, title+text+"\n" );
  write ( "你终於将心得写完了.\n" );
  return 1;
}
