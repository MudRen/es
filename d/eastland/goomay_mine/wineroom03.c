
#include <zeus.h>

inherit ROOM;
inherit DOORS;
void create()
{
  ::create();
  set_short("�ƾ�");
  set_long(@CLong
����һ�������ζ�ķ��䣬����ܱ�ʽ����ƣ�����û�������κε�ͨ���
���Գ�����֮�⣬���ܶ��ǹ�ͺͺ���ұڣ����ϰ�\������\��\���ľơ��ӣ���С
��ͬ��״Ҳǧ��ٹ֣��治֪������������˶����ֵľƣ��ϱ���һ����������
�ţ�
CLong
); 

set("exits",([
             "south":ZROOM"/wineroom02"
             ]));
create_door("south","north",([
            "keyword":({"gate"}),
            
            "name"   :"iron gate",
            "c_desc" :"һ�����ص�����",
            "c_name" :"����",
            "status" :"locked",
            "lock"   :"WINEROOM_DOOR",
            ]));
  set("objects",([
                 "drunk" : ZMOB"/mine_drunk",
                 "wine#1" : ZOBJ"/da_chu",
                 "wine#2" : ZOBJ"/da_chu"
                 ]));
reset();

}
void init()
{
  if(this_player()) this_player()->set_explore("eastland#15");
}
