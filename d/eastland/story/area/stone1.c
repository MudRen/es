#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��ʯ");
	set_long( @LONG
��վ��һ�鲻�ܴ�Ľ�ʯ�ϣ�������һ���޼ʵĴ󺣣����沨ƽ�˾���ֻ����
Щ��ˮ���������ﲻԶ����Ƭ��ɳ̲������������ι�ȥ ( swim ) ��
LONG
	);
        set("light",1);
        set("objects", ([
          "swordman1" : SMOB"swordman1"
        ]) ); 
	reset();
}
void init()
{
   add_action("do_swim","swim");
}
int do_swim( string arg )
{
   tell_object(this_player(),"������Զ���İ�ɳ̲��ȥ����\n");
   this_player()->move_player(SAREA"coast1","SNEAK");
   return 1;
}