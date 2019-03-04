#include <mudlib.h>

#define TMP_FILE "/tmp/monk.paper."+getoid(this_player())
#define WALL_FILE "/d/monk/doc/wall.txt"

inherit ROOM;

void create()
{
  ::create();
  set_short("Monk's history room", "�����¹�\�·�");
  set_long(
@C_LONG_DESCRIPTION
����Ǽ�¼������ɮ�����������������µĹ�\�µĵط���ټ��Ŀտ�����
�������߶����������а�(scroll)��������Ŵ��۾�հ��հ�������������\��\
���ľ�˵�������¿�����ʦү--��Ħ--�ĵ���(statue)����춴�˵�У�ֻҪ��
���ĳ��⸧��������\����������������������Ѿ�ģ�������ˡ�
    ����۹���ٵ�ɨ�����ܣ��ڲ����۵�ǽ�ǰ�\��һ�����ǻҳ��ġ����ף�
������ǰ����ɮ�ǽ��������ĵط��������׵��Ϸ���һ��ֽ��(paper),���浽
�����Ƕ϶��������������������������ѵ����书\�ĵ�����?
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
��������Զ����ǰ�Ĵ�Ħ���񣬾��а˷���˵�е�С��ʹ--Angel,һλ��ʷ����
�ͱ���ɮ�����С��ͷ�Ǵ�Ϊ�񻰵���������������ϸ�������ƣ���������һ����
�����Ӱ��--ruby��Ҳ��\��������λ�ľ����ע����������еĹ�ϵ��?!
    ��һ��������ʵ���̲�ס���еĳ嶯��ȥ����(touch)�������(statue)��
LONG
  );
    tell_room (
      environment (player),
      name + "��������ǰ�Ĵ�Ħ���񣬷�ϲ�������С�\n",
      player );
    return 1;
  }
  else if ( arg == "scroll" ) {
    me = users();
    for( i=0; i<sizeof(me); i++ )
      "/d/monk/guild/misc/topmonks"->log_player(me[i]);
    write (
      (string)find_object_or_load ( "/d/monk/guild/misc/topmonks")->get_list() );
    tell_object ( player, "�㶢�����а�ѽ���ģ�����Խ��Խ���ǰ�������µĹ�\��\n" );
    tell_room (
      environment (player),
      name + "�������а�ѽ���ģ����������˷ܵı��顣\n",
      player );
    return 1;
  }
  else if ( arg == "tatami" ) {
    tell_object ( player,
      "���ע���������ڡ��������棬��������:\n" +
      "  Ҳ��\���������(brood) ���Ը��ٵ�ǰ���ǵľ���!!\n");
    tell_room (
      environment (player),
      name + "�������ǻҳ��ġ����׿�ѽ���ģ���������˯һ����?!\n",
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
    tell_object ( player, "����ʲ��ط���֪����? ��Ҫ�洦����!!\n");
    tell_room (
      environment (player),
      name + "���������������������֪���ʲ�ᡣ\n",
      player );
    return 1;
  }
  tell_object ( player, 
    "  �㹧�����������˴�Ħ���ߵĵ���ͻȻ����:\n" +
    "��! ԭ�������ڷܵ�������ɡ�ѧ�������ɮ֮����!!\n" +
    "  �������۹�ŵ�ǽ�ǵġ�����(tatami)�������¾ɵ�\n" +
    "���ӣ������ǰ���ǽ�������ĵط���!!\n"
  );
  tell_room (
    environment (player),
    name+"�������ڴ�Ħ���ߵĵ��������������ƺ������������������һЦ ^_^\n" +
    name+"���۹⼯���ڷ�����ǽ�ǵġ��������档\n",
    player );
  return 1;
}

int do_brood (string arg)
{
  object me;

  me = this_player();
  if ( (int)me->query_temp ( "brood_flag" ) == 1 ) {
    tell_object ( me, "����ȥ����ʥ���ͻᱻ���Դ�Ŷ����һ�����붨������!!\n");
    return 1;
  }
  if ( !arg || arg != "tatami" ) {
    tell_object ( me, "�洦�Ҵ�������Ե�����ʥ����?\n");
    return 1;
  }
  tell_object ( me, "�㾲�������ڡ������Ͻ��, ˼���𽥿���, ������������֮��...\n");
  tell_room ( environment (me), "�㷢��"+
    me->query ( "c_name" )+"�������߶�ʮһ, ���ڡ���������������һ�㡣\n",
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
  tell_object ( me, "һ���˼֮��, ���˼����ˬ��, �����ص�����ʵ��\n" );
  tell_room ( place,
    me->query ( "c_name" )+"�����ҳ��شӡ�������վ��������\n",
    me
  );
  me->set_temp ( "brood_flag", 1 );
  call_out ( "reset_brood", 200, me );
  return ;
}

int reset_brood (object me)
{
  if (me) {
    tell_object ( me, "�㷢���Լ�����ʥ�����ǵ�˼·�У����н�Զ....\n" );
    me->delete_temp ( "brood_flag" );
  }
  return 1;
    
}

int do_write (string str)
{
  if (!str) return notify_fail ( "��Ҫд���ﰡ?\n" );
  if ( str != "paper" ) return notify_fail("*** ��-��-��-��-��-�� *** ��-��-��-Ϳ ***\n" );
  write("�뿪ʼ�������� -->\n");
  this_player()->edit(TMP_FILE, "process", this_object());
  return 1;
}

int process()
{
  string text, title;

  // seteuid(getuid());
  text = read_file (TMP_FILE);
  rm (TMP_FILE);
  title = (string)this_player()->query("c_name")+" � "+
        "/adm/daemons/weather_d"->query_c_game_time()+" д��:\n";
  write_file ( WALL_FILE, title+text+"\n" );
  write ( "����춽��ĵ�д����.\n" );
  return 1;
}
