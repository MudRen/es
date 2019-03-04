#include "irc.h"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Cliff","���±�" );
    set_long(
"You are standing on top of a cliff. One more step will take\n"+
"you to the deep darkness below. However you are quiet safe here,\n"+
"as long as you don't jump over to it. You noticed there is a bolt\n"+
"pinned near the edge.\n",
"��վ�����¶���, ���¿�ȥ��һƬ���, ��֪���ж���? ��ֻҪ�㲻\n"+
"������Ե���Լ�����ȥ, ���λ��ʵ���Ƿ羰����ĵط�. ��ע�⵽��Ե\n"+
"����һ���ֶ�(bolt)��\n"
    );
    set("exits", ([ "west" : IRC"lobby", ]) );
	set("item_desc",([
    	"bolt": "A bolt with a rope tide to it.\n\n",
    ]) );
    set("c_item_desc",([
    	"bolt": "һ���������ӵĸֶ���\n\n",
    ]) );
    set("busy",0);
}
 
void init()
{
    add_action("jump_down","jump");
}
 
int jump_down(string str)
{
	int i;
	if( !str || str!="down" ) return 0;
	if( query("busy") ) {
      write( can_read_chinese()?
        "������������.. �Ȼ�������? ��������ȥ��!\n" :
        "Someone is hanging down there, wait for your turn.\n" );
      return 1;
    }
    set("busy",1);
    write(can_read_chinese()?
        "��ʰ�����ӽ�֮��������, ������������\n":
        "You pick up the rope and tide to yourself, then jump down.\n");
	tell_room(environment(this_player()),({
	  this_player()->query("cap_name")+" tides the rope and jump over the cliff\n",
	  this_player()->query("c_cap_name")+"ʰ�����ӽ��Լ���ס, Ȼ����������һ����\n"
	  }),this_player()
	);
	this_player()->move_player(IRC"midair.c","SNEAK");
	return 1;
}
