
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("???","�ӱ�");
  set_long(@Long
Long
,@CLong
Ŀǰ��λ�һ����ֵĵط�, ���������ķ�����, ���ŵ����������ǿ��µĺ�ˮ.
��һ����ʾ��(plaque)��춵���, ���滹��һ���ܴ�ĺŽ�(horn).
CLong
);

set("c_item_desc",([
    "river":"��Щ���������ٷǳ��ǳ��Ŀ�, ����֮���㷢���ں����Ķ԰��ƺ�\n"
            "�и�С��.\n",
    "island":"һ��λ춺��е�С��, �����ƺ�������ֵ�ֲ�������, ���㲢����\n"
             "ȷ��, ��Ϊ����ʵ����̫Զ��.\n",        
    "horn"  :"һ���ܴ�ĺŽ�\n",
    "plaque":"��������ͨ������֮�ӵ���Ұ�֮���Ļ�,�봵(blow)�Ž�.\n",      
           ]) );

set("exits",([
     "west":Deathland"/dwarf/river02",
     ]) );
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
    
    write("��ңԶ�Ķ԰���Ȼ����һ����ֵĴ���, ����������������, ���Ҵ���\n"
          "Ѹ�ٵ�������, �������˾�����Խ���˺���,�����˶԰�.\n"
         );
    this_player()->move_player(Deathland"/island/i01",({
        "%s��һ����ֵĴ���������.\n","%s�ӿ��е�������.\n"
        }),"");      
    return 1;     
}
