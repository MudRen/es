#include <mumar.h>
inherit ROOM;
 
int ent;
void create()
{
        ::create();
  set_short("���е��ղ���");
  set_long( @CLong
���뾵�ڣ��㿴����ԭ��Ӧ�÷�ӳ�ھ��е��鱦��������������档�����Ǹ���
���ķ�����������Ǽ�ͽ�ıڣ��ͺ���ձ�ǿ��ϴ�ٹ�һ��������һ���ƾɶ�������
�ľ�����ֻ��һЩ�����ӡ��ռ����ˡ�
CLong
);
set("light",1);
set("c_item_desc",([
    "mirror":"@@to_mirror"
     ]) );
 
set("exits",([
               "down":MUMAR"m_square"
             ]));
}
 
void init()
{
    add_action("to_touch","touch");
    if(this_player()) this_player()->set_explore("eastland#25");
}
 
int to_touch(string arg)
{
   if( !arg || arg != "mirror" ) return 0;
   else  {
        write("�����������ӵ�ͬʱ����е�һ��ǿ������������������˾��ڡ�\n");
        this_player()->move_player(MUMAR"stage07",({
        "",this_player()->query("c_short")+"�������˾���\n��",
        "",this_player()->query("c_short")+"������������硣\n",
        }),"");
        }
   return 1;
}
 
string to_mirror()
{
   return "���澵����ҫ��һ������Ĺ�â���������������ȥ������\n";
}
