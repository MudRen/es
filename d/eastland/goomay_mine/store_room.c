

#include <zeus.h>

inherit ROOM;
int magic_metal;
void create()
{
  ::create();
  set_short("������");
  set_long(@CLong
������һ������ԭʼ��ʯ�Ĵ����ң���Щ��ʯ�������������ۣ�����ȴ��
���������ľ��Ѳ��ϣ�Ҳ��������ڴ˵��ҵ���˵�е�ħ��������
CLong
);
   

set("exits",([
             "north":ZROOM"/mine13"
             ]));
set("objects",([
             "iron troll":ZMOB"/iron_troll" ]) );
reset();
}

void init()
 {
    add_action("do_search","search");
 }    
void reset()
 {
   ::reset();
   magic_metal=1;
 }  
 int do_search()
 {
        object obj;   
      if(present("troll")) {
      write("�㿴�������Ժܲ����Ƶ��۹�ע�����㣮�����㼱��ææ��\n");
      write("������ʯѰ������ȴһ������\n");
      tell_room(this_object(),(
      this_player()->query("c_name")+"�ܼ�æ��������һ�飬¶����ʧ���ı��飡\n"),
               this_player() );
               return 1;
      }
     if (magic_metal){
       write("����ϸѰ��һ�飬�����ǽ���ҵ�һ��ںڵ�ʯͷ��\n");
       tell_room(this_object(),(
           this_player()->query("c_name")+"ͻȻ¶����ϲ�ı���!\n"),
           this_player() );       
       obj=new(ZOBJ"/magic_metal.c");
       obj->move(this_object());
       magic_metal =0;
       return 1;
                     }
     else
     {
       write("�������������˺þã�����û�з����κζ�����\n");
       return 1;
     }
 }
