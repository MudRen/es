
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("beach of GreyIsland","�Ұ�֮����ɳ��");
  set_long(@Long
Long
,@CLong
������ط����ܿ���һ������ֵ�����, �����ն�ĺ���֮��, ��������һ����
�µ�����, �����Ϸ���һ���ڰ���ɭ��, ����������һ��С��, ͨ��������ɽ��. ��
��պþ������е��εĽ��ᴦ.
��������һ����ʾ��(plaque), ���滹��һ���ܴ�ĺŽ�(horn). �Ա���һ�ž޴��
ֲ��, �������沼���˴���.
CLong
);

set("c_item_desc",([
    "river":"����������ٷǳ��ǳ��Ŀ�.\n",
    "horn" :"һ���ܴ�ĺŽ�\n",
    "plaque":"��������ͨ������֮�ӻص�ԭ���ĵط�,�봵(blow)�Ž�.\n",      
    "plant":"һ�ź���ֵ�ֲ��.\n",      
           ]) );

set("exits",([
     "east":Deathland"/island/swamp01",
     "northeast":Deathland"/island/mountain01",
     "southeast":Deathland"/island/forest01",
     ]) );
set("no_monster",1);
::reset();
}

void init()
{
   add_action("to_swim","swim");
   add_action("to_blow","blow");
}


int to_swim()
{
    write("���ˮ������̫������,��ʹ�����Ӿ�����ٺ�,����������º�ȥ�Ļ�,\n"
          "�㽫ֱ���ε�����������ǰ������.\n");
    return 1;      
} 
int to_blow(string str)
{
    if (!str|| str!="horn") return 0;
    
    write("һ����ֵĴ���, ����������������, ���Ҵ���Ѹ�ٵ���ǰ��, ��\n"
          "�����˾�����Խ���˺���,�ص��˶԰�.\n"
         );
    this_player()->move_player(Deathland"/dwarf/river03",({
        "","%s��һ����ֵĴ��ֵ�����.\n","","%s�ӿ��е�������.\n"
        }),"");      
    this_player()->set_explore("deathland#23");
    return 1;     
}
