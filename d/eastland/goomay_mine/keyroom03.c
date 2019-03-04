
#include <zeus.h>

inherit ROOM;
int x;
void create()
{
  ::create();
  set_short("�μҿ��ͨ��");
  set_long(@CLong
����һ��������ͨ����ǰ����ʧ�����������ֳ����ڵ��ϣ��������ϱ�
��ģ�����������\��\ľ���̶���������ǿ��ǹ����ĵط��ˣ�ͨ�������
�����б������ĺۼ���������һЩ����ֵֹ�С����������������������һ
�ɵ���������ζ������
CLong
);
set("item_desc",(["hole":"@@query_look"]) );
set("exits",([
             "south":ZROOM"/keyroom02"
             ]));
set("objects",([
              "overseer":ZMOB"/overseer",
              "miner#1":ZMOB"/miner02",
              "miner#2":ZMOB"/miner02"
              ]));

reset();
}     
void init()
{
add_action("to_throw","throw");
   }
   
int to_throw(string s)
{     string s1,s2;
      object obj1,obj2;
   if (!s){
           return notify_fail("���붪Щʲ��?  throw <somthing> to <location>\n");
          }       
   sscanf(s,"%s to %s",s1,s2);
   if (s1){
           if(!(obj1=present( s1,this_player())))
              return notify_fail("�����û����������\n");
           if(s1!="paper")    
                return notify_fail("���в����������Ķ��������ᶪ�ý�ȥ����\n");
           }               
   if((!s2)||s2!="hole")
                return notify_fail("��!��!��������ȥ?\n");
                
    if(this_player()->query_temp("paper/light")){                        
    write("�㽫ǧ�����С����һ����������һ�����죡�󷽵�ǽ�ڱ�ը���ˣ�\n");
    write("���ϳ�����һ�鷢���Ľ�����\n");
    obj1->remove();
    obj2=new("/d/eastland/goomay/obj/fire_key.c");
    obj2->move(this_object());
    this_player()->set_temp("magic/paper",0);
    tell_room(environment(this_player()),(
    this_player()->query("c_name")+"��ǧ��𶪽����������һ����ը���Һ���
    ��ʱ����û���ܵ��κ��˺�����Ļ�к�����ʲ�ᶫ��һ��һ���ģ�\n"),
    this_player());
    return 1;
    }else{
          write("���δ��ȼ��ǧ��𶪵�����ȥ�ˣ�\n");
          this_player()->set_temp("magic/paper",0);
          tell_room(environment(this_player()),(
          "��֪��"+this_player()->query("c_name")+"��ʲ�ᶪ�����\n"),
          this_player());
          obj1->remove();
          return 1;
          }
}
int query_look()
{
   if(this_player()->query_temp("magic/paper")){ 
write("����ϸһ�ƣ���Ȼ��һ���������С��������������ģ������ƺ��Ǹ���Ѩ��
��ʱ������һЩ���壬ԭ������ζ�����������﷢�����ģ�ż���㻹�ῴ��
һ������⣬��֪���������ʲ�ᱦ�\n");
}
else
   {write("һ����ƽ����С������������ɶ�ر�ĵط���\n");
   }
   }        