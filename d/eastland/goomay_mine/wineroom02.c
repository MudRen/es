
#include <zeus.h>

inherit ROOM;
inherit DOORS;
void create()
{
  ::create();
  set_short("�μҿ��ͨ��");
  set_long(@CLong
����һ��������ͨ����ż�������������ǵ�ߺ�������������п�����������
���˷�����ֵ�ζ����һ����ľ�������������������һ�����������ţ�
CLong
); 

set("exits",([
             "north":ZROOM"/wineroom03",
             "south":ZROOM"/wineroom01"
             ]));
create_door("north","south",([
            "keyword": ({"gate"}),
            
            "name"   : "iron gate",
            "c_desc" : "һ�����ص�����",
            "c_name" : "����",
            "status" : "locked",
            "lock"   : "WINEROOM_DOOR",
            ]));
            
            set("objects",([
                "guard#1":ZMOB"/wine_guard1",
                "guard#2":ZMOB"/wine_guard",
                ]));
reset();
}