
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
  set("light",1);
  set_short("���˹��ȵ����");
  set_long(@CLong
�����߿���ȥ,��һ���ܴ�ܴ�Ŀռ�,�������ǰ��˹���.�ڰ��˵����ڵ�
Ŭ��������,Ŀǰ���˹����Ѿ��ܹ��Ը�������.�������ɽ�����˵Ĺ���,����
�����������ྭӪ�������һ��.���԰���Ϊ�˱����Լ��ļ�԰,���ڼ�ǿ ����
�������������ʩ.
����ͨ�����˹��ȵ����,�㿴���м��ѵķ���������������.�����κ�ʱ��,��
���ڴ˵ص�������ʮ��ǿ��,��Ϊ������ͨ�����˹��ȵ�Ψһ·��.
CLong
);
set("exits",([
              "west":Deathland"/main/d7",
              "east":Deathland"/city/c2",
             ]));
set("objects",(["soldier#1":Monster"/soldier",
                "soldier#2":Monster"/soldier",
                "captain":Monster"/captain_1",
               ]) );
 create_door("west","east",([
             "c_desc" : "һ�Ƚ�ʵ���ص�ʯ��",
             "keyword" : ({"stone door","door" }),
              "name" : "stone door",
             "desc" : "A stone door",
             "c_name" : "ʯ��",
             "status":"closed",
              ]) );
  ::reset();
}
