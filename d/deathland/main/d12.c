
#include "../echobomber.h"
inherit ROOM;
void create(){
      ::create();
       set("light",1);
 set("short","��Ԩ���ϱ�");
 set("long",@Long_description
��������,������Ȼһ����ǿ��,����������(fog)ȴ������������,������
����ɢ������,���Ѿ��޷����������ĵ�����,�����Ա���С��������վ����
�ⱻǿ���ķ��ƴ����Ǹ�����������Ԩ.�����������𼫴��������������,
����ֻ�л�ͷ��.
Long_description
          );
set("item_desc",([
    "fog":@Fog
һ�ź���,���޷�����ؿ������о�����ʲ�ᶫ��.�������ܸо��������ƺ���
�����������.������ĺ�����ʮ��ǿ�ҵĻ�,��\��\��Ӧ���߽�����ȥ̽��,����
�㲻��ȷ�����ܻ����߳���.
Fog
                  ]) );
 set("exits",(["east":Deathland"/main/d10",
              ]));

}

int init()
{
add_action("walk_fog","walk");
add_action("walk_fog","enter");
}

int fog_1(object ob1)
{
  tell_object(ob1,@FFF
һ������������������˻���
FFF
     );
  ob1->move_player(Deathland"/main/d12","SNEAK","");
}

int walk_fog(string str)
{
if (!str||str!="fog") {
  write("Ϊ�β�������������?\n");
   return 1; }
else {
   if (this_player()->query_stat("karma")>=35) {
   call_out("fog_1",4,this_player());
   this_player()->move_player(Deathland"/fog/fog1","SNEAK","");
   }
   else
   write("��������������,���ȱ��һЩ����,���������Ԩ,"
         "�������ֻ�����˻���.\n");
     }
this_player()->set_explore( "deathland#3" );
return 1;
}