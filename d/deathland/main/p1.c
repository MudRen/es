
#include "../echobomber.h"
inherit ROOM;

void create()
{
        ::create();
        set("light",1);
        set_short("�ڰ�����");
        set_long(@Long_Description
һ���������ֲ�������,��Ľ��ƺ����ܺ�˳�����ƶ�.����Щ��ֵ�ֲ������
�����Ĵ��ֵ���Ѱ��ʳ��,��������һ���ǳ�Σ�յĵط�.
�ڱ���������һ������Ķ�Ѩ(hole),�����㲻ȷ����ͨ��δ�.
Long_Description
 );
  set("item_desc",([
      "cliff":"�ܸߵ�����.�кܶ������ֲ������������.\n",
      "hole":"һ������Ķ�Ѩ.\n",
      "plants":"һЩ��ֵ�ֲ��.\n",
                     ]) );

  set("exits",([
    "southwest":Deathland"/main/d1",
   ]));
}

void init()
{
     add_action("to_enter","enter");
}

int to_enter(string str)
{
   if (!str||str!="hole") return 0;
 
   write( 
           "�����������Ķ�Ѩ.\n");
   this_player()->move_player(Deathland"/main/d2.c",
      ({
      "%s���붴�ж���ʧ.\n",
        "%s������Ķ��е�������.\n"}),"");
   return 1;

}
