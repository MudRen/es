
#include <zeus.h>

inherit ROOM;
int dog;
void create()
{
  ::create();
  set_short("����");
  set_long(@CLong
����һ����������ȴ�ܼ�̵����� (bridge)��������Գ��ܼ��������
�����Ե�ˮ�Էǳ�����ٶ����������»�����һ������(net)�����ǲ�֪������
ʲ���ã����ϵ����쵽�������ƺ��Ѿ������յ㣮�ű���һ��С·ͨ�����£���
CLong
);
set("exits",([
             "south":ZROOM"/m_enter",
             "north":ZROOM"/mine01",
             "down":ZROOM"/port",
             ]));
set("item_desc",(["net":
"һ�����Ƶ����ӣ��ƺ���������ץ��ģ�Ҳ\��\�����������������������ʲ�ᣮ\n",
"bridge":@BB
һ����򵥵������ţ���������ҡҡ�λεģ��о�������ģ�����ҡҡ(shake)
�����Կ��᲻�����?
BB
]));
  reset();
 }
 void reset()
 {
    ::reset();
    dog=1;
 }
void init()
{
   add_action("do_shake","shake");
}
int do_shake(string str)
{  object ob;
   if(!str||str!="bridge"){
   write("�����ʲ��???\n");
    return 1;
   }
   
   if(dog){
   ob=new(ZMOB"/dog");
   ob->move(this_object());
   dog=0;
   return 1;
   }
   else {
   write("������ͱ�ҡ���������õ��ˣ���ҡ��ȥ�Ͷ��ˣ�\n");
   return 1;
   }
   
}   
   