
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
 set_short("the dwarf village","���˴�");
  set_long(@Long
Long
,@CLong
�����Ѿ��ǰ��˴���.����ȴ��һƬ�տ�,�ƺ�û���˾�ס������.ֻ����
һ�ھ�(well)�뼰������ˮ�õ�ľͰ,����֮���㻹����һ���ܴ�Ķ�Ѩ�ڶ�
��,һЩϸ΢�������Ӷ��д���,�ƺ�����ס�����������.
CLong
);
set("exits",([
                "west":Deathland"/dwarf/village_06",
                "east":Deathland"/dwarf/village_08",
             ]));
set("c_item_desc",([
    "well":"@@to_look_well",
    ]) );

}

string to_look_well()
{
     write("���㿴����ھ�,��Ȼ��ĽŻ���һ��,������˾���.\n\n\n\n\n"
          "\n\n\n\n\n"
          );
     say(this_player()->query("c_name")+"�ھ�����ʧ��.\n");
     this_player()->move_player(Deathland"/dwarf/well01","SNEAK","");
     return "һ������ľ�,���㻷������ʱ,�ƺ�û�з��ֳ���\n";
}
