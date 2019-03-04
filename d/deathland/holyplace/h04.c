//Deathland/holyplace/h04.c
//Created by Echobomber @Eastern.Stories

#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short(" Drawf holy place ","����ʥ��");
  set_long(@Long
Long
,@CLong
��Ŀǰ����һ��ħ��С����,���ܵ�����ʮ�ֵ�ǿ��,�ƺ���������һ��ǿ���ħ��
.����������ӿտյ�����,���˷����м���һ����ֵ�ˮ����(crystalball),�Լ���ˮ
������Ա���һ����ʾ(sign).
CLong
);

set("c_item_desc",([
    "sign":"����:��������(touch)���ˮ�����ʱ��,�㽫�����������ʥ�ĵط�.\n",
    "crystalball":"һ��ħ��ˮ����.\n",
    ]) );

set("exits",([
             "northeast":Deathland"/holyplace/r03",
             ]));
             

reset();
}

void init()
{
   add_action("to_touch","touch");
}

int to_touch(string str)
{
    if (!str||str!="crystalball") return 0;
    
    write("��������ˮ�����һɲ��,�������˺�Ȼ�ڿ�,Ȼ�ᵽ������һ���ط�.\n");
    
    this_player()->move_player(Deathland"/city/church",({
    "..\n","%s��Ȼ��������ʧ����Ӱ����.\n","..\n","��һ��ҫ�۵�ǿ����,%s����������ط�.\n"
    }),"");
    return 1;
}
