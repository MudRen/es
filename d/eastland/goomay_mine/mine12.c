
#include <zeus.h>

inherit ROOM;
int x;
void create()
{
  ::create();
  set_short("�μҿ��ͨ��");
  set_long(@CLong
����һ��������ͨ����ǰ����ʧ�����������ֳ����ڵ��ϣ��������ϱ�
��ģ��ϱ���һ����Ĺ��ţ�͸��һ����ֵĸо������Ա߻�����һ����
Ŀ������(sign)��������ż��������������������������
CLong
);   
set("item_desc",(["sign":@SIGN
   ������������������������������������������
   ������������������������������������������
   �����������صأ������˵������ٽ�����������
   ������������������������������������������
   ������������������������������������������
SIGN
     ]));
set("exits",([
             "south":ZROOM"/mine13",
             "northwest":ZROOM"/center2"
             ]));
set("pre_exit_func",([
                      "south":"to_pass",
                      ]) );             
reset();
}
void reset()
{
  ::reset();
    x=1;
}    
int to_pass()
{   object obj;
    int damage_hp;
    int initial_hp;
    int final_hp;
    int bounus;
    
    
   damage_hp = (int)this_player()->query("max_hp");
   initial_hp = (int)this_player()->query("hit_points");
   bounus = (int)this_player()->query_perm_stat("dex");
   final_hp = (initial_hp - (damage_hp/3) + bounus);
   if(present("pigeon")){
         x=0;
         obj=present("pigeon");
         obj->remove();
         tell_room(environment(this_player()),
         "���Ӻ����ܵ����ŵ����ӣ�ͻȻ�������ˣ�\n",
         this_player());
                  } 
   if(present("arrow")){
         x=1;
         obj=present("arrow");
         obj->remove();
         tell_room(environment(this_player()),
         "�������������һ����ը�ˣ�ֻʣ��һ�ѵķɻ����Ʈɢ��\n",
         this_player());
                 }
    if(x){
    write("**�������빰��ʱ��һ����İ����������컨�������Ϯ��������Ȼ�þ���\n");
    write("\n**�е�������Ȼ�޷����ⱻ���ˣ���\n\n");
    this_player()->set("hit_points",final_hp);
    return 0;    }
    else{
    x=0;
    return 0;    }
 }