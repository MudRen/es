#include <mumar.h>
inherit ROOM;
 
int ent;
void create()
{
        ::create();
  set_short("����ؽ̳�");
  set_long( @CLong
���ߵ�������ڵ�Ӫ�أ���Ƭ�յ���������������������Ƶ����񣬶��������
ʿ���ǵļҡ�������������ɱ��Ϣ������ɱ���Ĺ㳡�ϣ���ʵ�ں���������Щʿ����
����˯�������㳡�ı��濿ǽ�ĵط��и�ƽ̨(platform)��������һ��﷿��������
������㡣
CLong
);
set_outside("eastland");
 
set("c_item_desc",([
    "platform":"@@to_platform","door":"@@to_door"
     ]) );
 
set("search_desc",([
    "platform":"@@to_search_platform", "door":"@@to_search_door"
     ]) );
 
set("exits",([
               "south":MUMAR"square03",
               "east":MUMAR"kitchen",
               "west":MUMAR"square05",
             ]));
set("objects",([
               "soldier":MOB"old_soldier" ]) );
reset();
}
 
void init()
{
    add_action("to_enter","enter");
}
 
int to_enter()
{
   if (ent==1) {
     write("���ǹ����ģ�û�а�����û��Կ�׿ף���ʵ���벻�������..\n");
     }
   else
     {
     write("�����������..��ͻȻ������ʲ��Ҳ�Ȳ�����\n");
     write("��������ˤ����ȥ��ʧ������...����!!.....��\n.\n.\n.\n.\n.\n.\n.\n");
     this_player()->move_player(MUMAR"secret01",({
      "",this_player()->query("c_short")+"����������\n��",
      "",this_player()->query("c_short")+"������ˤ���������������ѿ��Ĳ�˵���е�Ҳ�ȴ����ġ�\n",
      }),"");
     }
   return 1;
}
 
string to_search_platform()
{
      return "������ϸ�������˾��̨ʱ��������̨���е�����(door)...\n";
}
 
string to_search_door()
{
    if (ent==1) {
      ent=2;
      return "������ϸ��������ʱ�����������µĻ��أ�����ͻȻ¡¡�ؿ���...\n";
      }
    else
      {
      ent=1;
      return "������ϸ��������ʱ�����������µĻ��أ�����ͻȻ¡¡�ع�����...\n" ;
      }
}
 
string to_platform()
{
    return "һ��˾��̨��վ��������Կ�������������ڵĻ���Ρ�\n";
}
 
string to_door()
{
  if (ent==1)
    return "һ��һ��ֻ����һ����ͨ����С����(door)��\n";
  else
    return  "һ��һ��ֻ����һ����ͨ����С����(door)�������ڿ�����\n";
}
 
void reset()
{
  ::reset();
  ent=1;
}
