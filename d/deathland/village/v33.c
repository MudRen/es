
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
    set_short("The flying room","Ʈ��֮��");
    set_long(@Long
Long
,@CLong
һ���򵥵��ķ���,��������ֵ�����û����,�ıߵ�ǽ�ڶ�����ش�,����֮�ⷿ��
���м���һ������,������������\��\����һ��ˮ����(crystalball),����֮�Ⲣû��������
������.
    ��һ��¥��ͨ��¥�ϵ�һ��С����,�ƺ��ǳ��ϵ���Ϣ��.
CLong
    );
    set("c_item_desc",([
        "crystalball":"һ�����ص�ˮ����.\n",
                ]) ); 
    set("exits",([
                "up":Deathland"/village/vr9",
             ]));
    ::reset();
}

void init()
{
     add_action("to_touch","touch");
}

int to_touch(string str)
{
    if (!str|| (str!="crystalball"&&str!="ball")) return 0;
    else 
      {
        write("һ�ɺ���ӿ���������ͷ,��Ȼһ����͵Ĺ�����������,����˺�Ȼ�������ñ���.\n");
        this_player()->move_player(Deathland"/village/v32",
         ({"%s����������.\n",
         "%s������һ������������.\n"}) );
        return 1;  
      }
}  
   
