
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("mountain of GreyIsland","�Ұ�֮����ɽ��");
  set_long(@Long
Long
,@CLong
������С��������������ɽ����, ��ط�ʵ���Ǹ��ܹŹֵĳ���, ��˵�ǻҰ���
��ɽ��, ������ȴ�������ͷ�����������ĺ���������ʯ, ��Ҳ������ĵ�������
�������ٵĺ�ˮ.
    ��������һ����ǿ���������赲�������ǰ��. �ǵ������ƺ�����һ���������
��, ��Ҫ�����������Ʒ��������ͨ��.
CLong
);

set("exits",([
     "southwest":Deathland"/island/mountain01",
     "east":Deathland"/island/mountain03",
     ]) );
set("pre_exit_func",([
    "east":"to_east",
    ])); 
 ::reset();
}

int to_east()
{
    object *items;
    int i;
    
    items=all_inventory(this_player());
    for(i=0;i<sizeof(items);i++) 
      if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
        if (items[i]->query("quest_item/crystal_card")) {
          write("���ˮ��������ǽ��������Ӧ,�����ͨ������ǽ.\n");
          return 0;
          }
    write("���޷�ͨ����ǽ.\n");
    return 1;   
}
