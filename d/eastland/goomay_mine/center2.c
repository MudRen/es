
#include <zeus.h>

inherit ROOM;

void create()
{
  ::create();
  set_short("��Ӵ���");
  set_long(@CLong
������ʮ�ֿ����ĵط�����\��\��İ����ӣ��ɼ��˵��ǿ�����Ϣ�ĵط���
���������䱻����ɰ����ͣ�����֩���������ĵ㣬�ǿ��ƿ���ڸ����ڵ���Ҫ
��Ŧ��Ҫ�����ӵ��κν��䣬�����뾭���˵أ�
CLong
);
   

set("exits",([
             "west":ZROOM"/center1",
             "north":ZROOM"/center3",
             "southeast":ZROOM"/mine12",
             ]));

reset();
}
void init(){
add_action("south_wall","push");
      }
int south_wall(string ob)
{     

string him;
      him =(string)this_player()->query("c_name"); 
      if(!ob||ob !="south wall") 
      { write("��ʹ���˳��̵�������������һ��Ҳ����!\n");
        tell_room(environment(this_player()),(
        "�㷢��"+him+"��Ŭ������ǽ��ײȥ���㻳�������Դ��ǲ���װ�ݵģ�\n"),
        this_player());
      return 1;      
        }
      else
      {
      
      write("\n��������ǽ��һ�ƣ�ͻȻ������������ǽ��.\n");
      tell_room(environment(this_player()),(
      him+"ͻȻ��ǽ����ʧ�ˣ�\n"),
      this_player());
      this_player()->move_player(ZROOM"/control.c","SNEAK");
      } 
      return 1;
 }