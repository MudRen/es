#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("ɽ��");
	set_long( 
@LONG_DESCRIPTION
�����������Ļ�ɽɽ���ƺ�����������Ũ��ð������֪��ʱ�����ٱ����������
����ǳ����ȣ���������������������������ȥ�����ﵽ�����ǻ�ɽ�Һ͸�ʯ������
�ɻ�ɽ�������ɵĻ�ɽ����춵����Ǿ޴���ѷ죬����뵽��ɽ�����൱���ѵģ���
վ��ɽ���������������һ�ñ���Ǭ����ľ��̧ͷ������ȥ����������Ҫ�����ɽ
����һ��ξ��룬��������Ϣһ�°ɡ�
LONG_DESCRIPTION
	);

/* set("search_desc",([
    "here":"@@search_here",
    ]) ); */

set( "exits", ([
     "southwest" : ONEW"varea2",
     "northwest" : ONEW"varea3" 
     ]) );
set_outside("eastland");
reset();
}

string search_here()
{
      return "\n"; 
      write( 
           "�������������Ѱ��һȦ��������һ֦��(branch)�ֵֹġ�\n"+
           "���֦�ɺ��е��ԣ����������ȥ��������\n");
}

void init()
{
/*    add_action("do_pull","pull"); */
}

int do_pull(string arg)
{   
    if (!arg || arg!="branch")
    { write(
        "���������һЩ��ֵĶ���.....���ϴ���һ��Ц��....������ʲ������\n");
      tell_room(this_object(),this_player()->query("c_name")+"������һЩ��ֵĶ�����\n",this_player());
      return 1;
    };
    write( 
          "�����ϳ���һ���󶴣����Ų���������ȥ....\n"+
          "��տ�������֮�У�����һ��������ˤ����ȥ...\n"+
          ".....\n\n......\n\n...\n\n..........\n\n...\n\n.....\n"+
          ".........\n\n......\n"+
          "�㷢�������ڻ�ɽ��ɽ���С�\n");
    this_player()->move_player( ONEW"mcave1.c","SNEAK" );
    tell_room(this_object(),"�����"+this_player()->query("c_name")+"��ʧ�������ǰ��\n",this_player());
    return 1;
}
