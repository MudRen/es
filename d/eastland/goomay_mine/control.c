
#include <zeus.h>

inherit ROOM;
int number;
void create()
{
  ::create();
  set_short("���ط�");
  set_long(@CLong
�����ǿ���ڵĻ����صأ��Ƕ���һ��Ϊ�˱������ά����������Ŀ�ӣ���
���Ļ����ң���������˿�������е���Ҫ���أ��㿴��һ������(lever) ������
�͵����⣬�ض���ʱ�������Ļ��أ������Ϸ���һ����������ӣ����淢��һЩ��
�ֵ�����������ǰ��һ��СС�Ķ�(hole)��
CLong
);
set("item_desc",(["lever":
"����һ�����������ɵ����ˣ��ƶ�����֪������ʲ�������\n",
"hole":"һ��СС��ͨ�������滹��Щ��\����\�࣡\n"
]) );

set("exits",([
             "north":ZROOM"/center2"
             ]));
set("objects",([
    "mine_master":ZMOB"/mine_master",
    ]) );
reset();
}
void reset()
{
   ::reset();
   number=1;
}

void init()
{
  add_action("do_pull","pull");
  add_action("do_push","push");
  if(this_player()) this_player()->set_explore("eastland#16");
}
void to_fly(int x)
 {   object obj;
     if(x){ 
     tell_room(environment(this_player()),(
     "������ž��ž����������ͻȻ��һֻ���ӴӶ���ǽ�ǵ�С�����˳�ȥ��\n"
                                   ));
     
                                   
     obj=new(ZMOB"/pigeon");
     obj->move(ZROOM"/mine12");   
     tell_room( environment(obj),
     "������ž��ž����������һֻ�ɰ��ĸ��ӷ��˽�����\n",
     this_player());                              
//     this_player()->set_temp("mine/damage",1);                                    
               }
     else{
     tell_room(environment(this_player()),(
     "ͻȻһֻ�����������ļµ��������Ӷ���С�������\n"
                                  ));
     
     obj=new(ZOBJ"/arrow");
     obj->move(ZROOM"/mine12");
     tell_room(environment(obj),
     "һ�����񺿵������ᣬһֻ���Ͳ�����Ľűߣ��ݷ��ھ������㣡����\n",
     this_player());
//     this_player()->set_temp("mine/damage",0);
        }
}
int do_pull(string str)
{
   if(!str||str!="lever"){
   write("��Ҫ��ʲ��??????\n"); 
   return 1;
                         }
      if(number==0){
      write("�������Ѿ����������ˣ�\n");
      return 1;
            }             
   if (!present("master")) {
   write("������������һ�����ƺ�������ʲ�����.\n");
   tell_room(environment(this_player()),(
      "��"+this_player()->query("c_name")+"��������ʱ��������һ������\n"),
             this_player() );
   call_out("to_fly",1,1);
   number=0; 
   return 1;
                           }
   else
      {write("���ϴ�˵:���ʲ��!!!��Ҫ���Ǹ�����!!!!\n");
      tell_room(environment(this_player()),(
      this_player()->query("c_name")+"��Ҫ������ʱ�������ϴ�����һ�٣�\n"),
              this_player() );  
   return 1;
   }
}
int do_push(string str)
{
   if(!str||str!="lever"){
   write("��Ҫ��ʲ��??????\n"); 
   return 1;
                         }
      if(number==1){
      write("�������Ѿ����Ƶ����ˣ�\n");
      return 1;
            }             
   if (!present("master")) {
   write("������������һ�����ƺ�������ʲ�����.\n");
   tell_room(environment(this_player()),(
      "��"+this_player()->query("c_name")+"�ƶ�����ʱ��������һ������\n"),
             this_player() );
   call_out("to_fly",1,0);
   number=1;
   return 1;
                           }
   else
      {write("���ϴ�˵:���ʲ��!!!��Ҫ���Ǹ�����!!!!\n");
      tell_room(environment(this_player()),(
      this_player()->query("c_name")+"��Ҫ������ʱ�������ϴ�����һ�٣�\n"),
              this_player() );
   return 1;
   }
}
