
#include "../echobomber.h"
inherit ROOM;
inherit DOORS;
void create(){
      ::create();
       set("light",1);
       set("short","һ������Ķ�Ѩ");

       set("long",@Clong
������������ط�ʱ,�㷢�ֶ��ߵ��ұ�����һ��ʯ��(stone door),����
������һ������(board),��������һ���ܴ�Ķ�Ѩ,������һ��б��,ͨ��δ֪
���,���ϱ���һ�����ϵĶ�Ѩ.��ӵصײ�ͣ�ش�����,�����Խ��Խ����.
Clong
          );
set ("item_desc",([
"board":@Board
 ---------------------------------------------------------------------
       ����ͨ�����˹��ȵ����,������Ը��������ǶԿ�а���ɽ�����˵�
       ��,��ӭ��,�ҵ�����.
                         --�ʼ������ӳ� ��������(Calford)
---------------------------------------------------------------------
Board
 ]));
 set("exits",(["southup":Deathland"/main/d3",
               "west":Deathland"/troll/cave_01",
               "east":Deathland"/city/c1",
               "northdown":Deathland"/main/d8",
              ]) );
create_door("east","west",([
             "keyword" : ({"stone door","door" }),
             "status" : "closed",
             "c_desc" : "һ�Ƚ�ʵ���ص�ʯ��",
             "c_name" : "ʯ��",
             "name":"stone door",
             "desc":"a stone door"
              ]) );
reset();
}
