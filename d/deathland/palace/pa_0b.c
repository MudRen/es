
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("secret room","���ܷ���");
  set_long(@Long
Long
,@CLong
һ�����ܵķ���,�ǰ���Ϊ���ھ��˹����ʹ�ʱ��һЩ�����������õ�.������һ����
��ͨ������Ĵ�����.
CLong
);
set("exits",([
               "up":Deathland"/palace/pa_02",
             ]) );
set("c_item_desc",([
    "ladder":@Cladder
һ��ͨ�������ҵ�����.
Cladder
    ]) );
set("objects",([
    "guard":Monster"/royal02",    
    ]) );
    
::reset();
}

void init()
{
    add_action("to_climb","climb");
}

int to_climb(string str)
{
   if (!str||str!="ladder") return 0;
   if (!present("guard")) {
     write("����������,��������\�òŵ�������\n");
     say(this_player()->query("c_name")+"����������\n");
     this_player()->move_player(Deathland"/dwarf/pass02","SNEAK","");
     say(this_player()->query("c_name")+"������������\n");
     }
   else {
     write("�������㵲ס����������ȥ\n");
     say(this_player()->query("c_name")+"�����������ӵ���������ס\n");
     } 
   return 1;
}
