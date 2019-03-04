//File: book_temple1.c �ؾ���ǰ�յ�

#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "�ؾ���ǰ" );
       set_long( @C_LONG_DESC
���ߵ�һ��С�ӱߣ��ӱߴ�����һ��¥��ԭ������Ǵ��������������²�
����(library)���������������������ѧ���⡣������ȥ(enter)��ʶ��ʶ��
���Ǹ������ܲ����۴�������ɮ�������е�վ��һ������һ�����ػ��ؾ����
ɮ�ˣ�������һ�����������㣬̫��Ѩ�߸߹�����ض���������޵ĸ��֡���
�����һ���ؾ����ںӱߣ��ȷ����ֿɷ�����ʵ���Ǹ���֮����
C_LONG_DESC
        );
        set( "objects",([
            "monk1" : SAULIN_MONSTER"book_guard",
            "monk2" : SAULIN_MONSTER"book_keeper"  ]));
        set_outside("eastland");
    set("exits",([
       "west"  : SAULIN"stone_path2",
       "north" : SAULIN"river_side3",
       "south" : SAULIN"river_side4",
    ]) );
    reset();
}

void init()
{
    add_action( "enter_library", "enter" );
}

int enter_library(string arg)
{
	if( !arg || arg != "library" )
   		return notify_fail("������Ķ�ȥ����\n");
 	if( (present("guardian") || present("keeper") ) && (!wizardp(this_player())) &&
 		     (!this_player()->query_temp("book_quest/step")) ) {
      tell_object(this_player(),@ENTER_LIB
�������ҡ���\���߽��ؾ���ͻȻ�ظ�ɮ�����˹��������ʮ����
    �ؾ���Ϊ�����صأ�ʩ�������ô� !!
����������΢΢�������ϵ�ɮ��ͻȻ������������ֻ����һ��ǿ��
����������ѹ�����̲�ס���������Ĳ���
ENTER_LIB
);
      return 1;
	} else {
      tell_object(this_player(), 
      	"����û����������ֹ���ˣ����ҡ���\���߽��ؾ���\n");
      this_player()->set_temp("book_quest/step",0);
	  this_player()->move_player(SAULIN"book_temple2","SNEAK");
	  return 1;
	}
}
