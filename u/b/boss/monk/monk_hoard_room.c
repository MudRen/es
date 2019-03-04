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
  set ( "item_desc", ([
        "book" : @BOOK_LONG
        �Ȿ��ķ���д�����ļ����� : ������ɮ¼
        
    �⼸���ֿ������ɷ����, ����������������ص�һ����ʮ��������ǰ�����¼���
������뽫������ (open) ���� (read) ....... 

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
        write("�����Ѿ������ˡ�\n");
    else {
        set("book_status","open");
        write("����Ȿ������ɮ¼��\n");
    }
    return 1;
}

int do_close(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
        can_look=query("book_status");
    if ( can_look=="close" )
        write("�����Ѿ���������.\n");
    else {
        set("book_status","close");
        set("book_page",0);
        write("������Ȿ������ɮ¼��\n");
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
             return notify_fail("���ȴ���.\n");
       page=(int)query("book_page")+1;
       page=(page==LAST_PAGE)?0:page;
       write("����鷭���˵�"+ page +"ҳ.\n");
       set("book_page",page);
    }
    else if ( sscanf(str,"page to %d",page)==1 )
    {
       if ( (string)query("book_status")=="close" )
            return notify_fail("���ȴ���.\n");
       write("����鷭���˵�"+ page +"ҳ.\n");
       set("book_page",page);
    }
    else
       write("����ķ�������:turn page or turn page to <num>.\n");
    return 1;
}
                                                
int do_read( string str )
{

    if( !str || str=="" ) {
        write("��Ҫ��ʲ�᣿\n");
        return 1;
    }
    if ( (string)query("book_status")=="close" ) {
        write("���ȴ���.\n");
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
��������Զ����ǰ�Ĵ�Ħ���񣬾��а˷���˵�е�С��ʹ--Angel,һλ��ʷ����
�ͱ���ɮ�����С��ͷ�Ǵ�Ϊ�񻰵���������������ϸ�������ƣ���������һ����
�����Ӱ��--ruby��Ҳ��\��������λ�ľ����ע����������еĹ�ϵ��?!
    ������Ħ������ǰ���������Ϸ���һ����(book), �����������µġ�
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
  return 0;
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

  text = read_file (TMP_FILE);
  rm (TMP_FILE);
  title = (string)this_player()->query("c_name")+" � "+
        "/adm/daemons/weather_d"->query_c_game_time()+" д��:\n";
  write_file ( WALL_FILE, title+text+"\n" );
  write ( "����춽��ĵ�д����.\n" );
  return 1;
}
