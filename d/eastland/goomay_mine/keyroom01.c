
#include <zeus.h>

inherit ROOM;
int paper_num;
void create()
{
  ::create();
  set_short("�μҿ��ͨ��");
  set_long(@CLong
����һ��������ͨ����ǰ����ʧ�����������ֳ����ڵ��ϣ��������ϱ�
��ģ���������\��\��\ľ���̶���ǰ��ż�������û������������ܿ쵽���
�ǲɿ�ĵط��ˣ�ͨ��������ϣϣ�����ɢ��������ʱ���µ��ѷ죮
CLong
);
set("item_desc",(["crack":
"����һ������ʱ���µ��ѷ죬��ϡ���Կ���һЩ��������϶���У�\n"
    ]) ); 

set("exits",([
             "north":ZROOM"/keyroom02",
             "southwest":ZROOM"/center3"
             ]));

reset();
}
void init()
{
 add_action("do_search","search");
 }
 void reset()
 {
    ::reset();
    paper_num=1;
 }   
 int do_search(string str)
 {     object obj;
       if (!str||str!="crack"||(int)this_player()->query_temp("get/paper_torch")!=1) {
       write("���������ﰡ��������������Ҫ�ѵ�����ร�\n"); 
       return 1;
                                }   
       if (paper_num){
       write("���˲��˵Ļ��ᣬ���������ѷ���ϸ��ȥ������ͳ�һ����ֵ�ֽ\n");
       tell_room(environment(this_player()),(
       this_player()->query("c_name")+"���������ѷ�����Ѱ\n"),
       this_player() );
       this_player()->set_temp("magic/paper",1);
       obj=new(ZOBJ"/paper_torch.c");
       obj->move(this_player());
       paper_num=0;
       return 1;
                     }      
}
