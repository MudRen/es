
#include "../echobomber.h"

inherit DOORS;
inherit ROOM;
void create()
{
	::create();
  set("no_monster",1);
  set("light",1);
  set_short("","�����");
  set_long(@Long
Long
,@CLong
���˹���Ī���������������.ĿǰĪ���»���ĳ�Աֻʣ�¹���Ī��������
,�ʺ�����˿(Lilies),�Լ����ǵĶ����Ӱ���(Air).����ӷ�����(Falady )��һ
һ�εľ�������ʱΪ����ֹ���˼�˾�����������(Hotredchili)�ĺڰ�ħ����Ӣ
�µ�������,�����˵Ĺ���Ҳ����ܴ�.����ս����δ��˽���.����������Ҫһ��
�¸ҵ�Ӣ������������.
�����ǻʺ�����˿���޹�,����,���������������ӵķ���.
CLong
);
set("exits",([
               "east":Deathland"/palace/pa_08",
               "north":Deathland"/palace/pa_09",
               "south":Deathland"/palace/pa_0a",
               "west":Deathland"/palace/pa_02",
             ]));

set("objects",([
    "king":Monster"/king",
   ]) );


create_door("east","west",([
             "name":"gold door",
             "c_name":"��ɫ����",
             "keyword":({"gold door","door",}),
             "c_desc":"��ɫ����",
             "status":"locked",
             "desc":"a gold door",
             "lock":"ECHO_DWARF_CITY_1",
                     ]) );
  ::reset();
}
