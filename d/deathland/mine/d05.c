
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" the big cave of Drawf mine ","���˿�ӵĴ�Ѩ");
  set_long(@Long
Long
,@CLong
һ���ܺںܰ��Ĵ�Ѩ,�����Ǹ������ḻ�Ŀ��.������ĵ��ϳ����˺�ɫ��
��ĭ��һЩ�Ǻ�. �ڵ�����һ��ˮ��(pool),���洫��һЩ����������,�ƺ�������
���ȥ������.
CLong
);
set("c_item_desc",([
    "pool":"һ��СС��ˮ��,���ƺ��������ס������.\n",
//    "skeleton":" ",
//    "bubble":" ",
    ]) );
set("exits",([
             "east":Mine"/d04",
             ]));
reset();
}
void init()
{
   add_action("to_enter","enter");  

}

int to_enter(string str)
{
   if (!str || str!="pool") write("Enter what.\n"); 
   else {
     write("�������ˮ��.\n");
     this_player()->move_player(Mine"/d06",({"%s enter the pool.\n","%s������ˮ��",
       "%s enters from outside.\n","%s �������������.\n"}),"");
     } 
   return 1;
}
