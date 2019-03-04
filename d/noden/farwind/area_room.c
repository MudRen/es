//#pragma save_binary

#include <mudlib.h>
#define LAST_PAGE 5
#define AREA "/doc/area/area_"

inherit ROOM;

void create()
{
	::create();
	set_short( "ð����֮��" );
	set_long(@C_LONG
��������վ��һ�������������յĴ���֮�У������������ĳ�ְ�
�д�������ɫ��·��ʯ�Ľ��ɵģ�һЩ��ɫ��ֲ���Ư���Ļ���װ������
�����ܵ�Բ���������ǽ���ϵ������Ϊ������ͼ��������������������
һ���ܴ���鱾( book )������С������и�ͨ��, ����ͨ��������á�
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
    "̽��\n"
     "һ����������������ð��������¼�µĸ����������.\n"
    );
    return 1;
}

int to_open(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
    can_look=query("book_status");
    if ( can_look=="open" ) 
      write("�����Ѿ�������.\n");
    else {
      set("book_status","open");
      write("���̽����֮��.\n");
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
      write("�����̽����֮��.\n");
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

int to_read(string str)
{
    if (!str||str!="book") return 0;
    if ( (string)query("book_status")=="close" )
            return notify_fail("���ȴ���.\n"); 
    cat(AREA+query("book_page"));
    return 1;
}

