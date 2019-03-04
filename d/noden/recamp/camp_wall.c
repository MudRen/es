#include <mudlib.h>
#include "camp.h"
inherit ROOM;

int apply_wall ; // ��ʾ�Ѿ���ī
int apply ;      // ��ʾ apply ����춴�
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
	
    set_short( "ʯ��" );
	set_long( @C_TOPIC
���ʯ�ҿտ������ģ����ҹ����ֲ�̫���㣬���䴦������ʲ���ڶ���ʯ��
��ǰ������(wall)��������һ����ֵĹ��ġ�����ǰ��ϸ���������������Ǻ�
����ָ���̻����µġ��Աߵ��Ϸ��˸�����(box)�������Ժܾ�û�˶����ˡ�
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
    return "������ӣ����������һ���ɫʯͷ��\n"; 
}

string search_here()
{
    object ob;
    if ((papermob) || present("sheet",this_object()) ) return
      "�������ϰ��죬��û���ҵ�ʲ�ᶫ��!!\n" ; 
    else {
      ob = new( CAMPMOB"paper_mob" );
      ob->move(this_object());
      papermob = 1 ;
      return "ͻȻ�����ʲ��һ�����³����Ķ���Ʈ�˹�ȥ���㲻���ų�һ���亹��\n"; 
    }
}

int msg_box()
{
    write("�����ľ�䣬�����������ۣ���մ��Щī�Ƶġ�\n"
    );         
    return 1;
}

int msg_wall()
{
  if (!apply_wall) {
  write("��Ƭʯ���Ͽ�������ֵ����֣�Ҳ��\����������ร���취��ӡ�����ɡ�\n" );
  } else {
  write("ʯ���Ͽ�������ֵ����֣������Ѿ���ī�ˣ�Ҳ��\��Ǭ����!!\n") ;  
  }
  return 1;
}

void to_find_wall( string arg )
{
  write(
    "���ú�ɫʯͷ��ʯ�������ֶ�Ϳ��һ�飬�۵�����󺹡�\n"
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
