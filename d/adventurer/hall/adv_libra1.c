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
        set_short("ð����������");
	set_long( @C_LONG_DESCRIPTION
������ð����ר���������ң�ǽ�Ϲ���������ĵ�ͼ�����԰壬������м�
��һ�ŷǳ����д��̨��д��̨�Ϸ���һ����������������(note)  �Լ�һ��ͼ��
(book)�����ð����Χ��д��̨�Խ�ͷ�Ӷ�����֪������Щʲ��?
C_LONG_DESCRIPTION
	);

	set( "item_desc", ([ 
		"book" : @LONG_BOOK
�Ȿ������ͼ������һλ�����������ð�ռ�����һ����׫����Ѫ�ᾧ��ͼ���м�
���������ھ��󲿷ݵ������������飬ĳЩ���Ｋ�亱����ĳЩ��������࣬��
�����������ɹ��Ľ��־���ֲ�����ĵס���ð�����ǲ�С���������ǣ�����������
�ֲ���ͻȻ����������������ǰ�Ը�����������ʶ���Ϳ��Ա��ⲻ�ҵķ���������
��֮ǰ��������ȴ��飬����(read)�Ȿ�������(index)��
LONG_BOOK
,               "note" : @LONG_NOTE
�Ȿ��������������������������������;���������ţ�������Щ����ʵ�ģ�Ҳ��
һЩֻ��ҥ�Լ�����ʵ�ʵĻ��롣��ֻ���о����Ҵ����������߲��ֱܷ�����α��
�����ʹ��readָ��������������ص����ݣ�Ҳ������write ���Լ��������ż���
��ȥ������˵�Ȿ����Ү����������ϲ�������ж���������ˮ���˽����ܵ���
�������Ĵ�����
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
               "c_desc":"һ��СС��ľ��",
               "c_name":"Сľ��",
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
      write("�����Ѿ������ˡ�\n");
    else {
      set("book_status","open");
      write("����Ȿ����ͼ����\n");
      }
    return 1;    
}

int to_close(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
    can_look=query("book_status");
    if ( can_look=="close" ) 
      write("�����Ѿ���������.\n");
    else {
      set("book_status","close");
      set("book_page",0);
      write("������Ȿ����ͼ����\n");
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
	if( str=="index" ) {
	    this_player()->more( MOB_INFO"c_list",0,1);
	    return 1;
	    }
	if( str=="note" ) {
	    this_player()->more(NOTE_FILE,0,1);
	    return 1;
	    }    
	if ( (string)query("book_status")=="close" ) {
	    write("���ȴ���.\n");
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
	if (!str) return notify_fail("��Ҫд���ﰡ?\n");
	if (str != "note") return notify_fail("��Ҫ�һ��... \n");
    write("�벻Ҫ�ڴ�����quest���ˮ....\n");
    write("��ʼ��������....\n");
	this_player()->edit(TMP_FILE, "process", this_object());
	return 1;
}
 
int process()
{
    string text, title;
    seteuid(getuid());
    text = read_file(TMP_FILE);
    rm(TMP_FILE);
    title = (string)this_player()->query("c_name")+" � "+
        "/adm/daemons/weather_d"->query_c_game_time()+" д��:\n";
    write_file(NOTE_FILE, title+text+"\n");
    write("Ok.\n");
	return 1;
}
int check_flag()
{
      if ( wizardp(this_player()) || !present("avery")) return 0;
      if ((string)this_player()->query("class") != "adventurer" ) {
        tell_object( this_player(),
        "������˵��: �Ǳ�ֻ��ð�����ܽ�ȥ...\n");
        return 1;
       }
       else return 0;                
} 

int clean_up() { return 0; }
