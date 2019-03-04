
#include <zeus.h>

inherit ROOM;
int boxes_num;
void create()
{
  ::create();
  set_short("�μҿ��ͨ��");
  set_long(@CLong
����һ��������ͨ����ǰ����ʧ�����������ֳ����ڵ��ϣ��������ϱ�
��ģ���������\��\��ľ���̶���ǰ�洫���û�������Խ��Խ��Ӧ�ÿ쵽��
���ǲɿ�ĵط��ˣ�ͨ��������ϣϣ�����ɢ��������ʱ���µ��ѷ��һ
Щ�Ź��ߵ����ӣ�
CLong
);
set("item_desc",(["crack":
"����һ������ʱ���µ��ѷ죬��ϡ���Կ���һЩ��������϶���У�\n",
"box" : "����\��\�๤�����е�һ����û��ʲ���ر�ĵط����������������Ӱɣ�\n",
"boxes":"����һЩ�����䣬Ҳ\��\�����������ҵ�һЩ���õĶ�����\n"
    ]) ); 

set("exits",([
             "north":ZROOM"/keyroom03",
             "south":ZROOM"/keyroom01"
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
    boxes_num=1;
 }   
 int do_search(string str)
 {     object obj;
       if (!str||str!="boxes") {
       write("���������ﰡ��������������Ҫ�ѵ�����ร�\n"); 
       return 1;
                                }   
       if (boxes_num){
       write("�����ְ����ӷ������������һ����ֵ�ֽ\n");
       tell_room(environment(this_player()),(
       "�㿴��"+this_player()->query("c_name")+"�����ӷ�������֪������ʲ�᣿��\n"),
       this_player() );
       obj=new(ZOBJ"/mine_scroll.c");
       obj->move(this_player());
       
       boxes_num=0;
       return 1;
                     }
}