#include <mumar.h>
inherit ROOM;
 
int ent;
void create()
{
        ::create();
  set_short("������ղ���");
  set_long( @CLong
�߽�������䣬�㼸�������Լ��ǲ������һ�����»���֮�С���������ĳ�
�費˵���ղصĸ����Ǹ��ص�������Ʒ�͹��档ҫ�۵��鱦(gems)�ʹ���(china) ��
�⣬�������Щ��Ȥ�Ŀ���(plates)�������������������ӵ���ⷿ����ʮ��֮һ��
�Ƹ�������°뱲�Ӷ���������׬Ǯ�ˡ�
CLong
);
set("light",1);
set("c_item_desc",([
    "gems":"@@to_gems","china":"@@to_china",
    "plates":"@@to_plates","mirror":"@@to_mirror"
     ]) );
 
set("exits",([
               "west":MUMAR"stage06"
             ]));
}
 
void init()
{
    add_action("to_polish","polish");
    add_action("to_touch","touch");
}
 
int to_polish(string arg)
{
 if( !arg || arg != "plates" ) return 0;
   write("��С������ص�������������ף�ȴ����һ����С�Ĳ���һ��ս��Ū����\n");
   write("������ͼ������ս��ʱ��ŷ��ֿ�������Ľ��������һ������(mirror)��\n");
 this_player()->set_temp("look_mirror",1);
 return 1;
}
 
int to_touch(string arg)
{
   if( !arg || arg != "mirror" ) return 0;
   else  {
      if (this_player()->query_temp("mirror_ok") || ent==2){
        ent=2;
        write("�����������ӵ�ͬʱ����е�һ��ǿ������������������˾��ڡ�\n");
        this_player()->move_player(MUMAR"m_stage",({
        "",this_player()->query("c_short")+"�������˾���\n��",
        "",this_player()->query("c_short")+"����������������硣\n",
        }),"");
        }
      else {
        ent=1;
        write("��������������ӣ��������һ�ֵĻ�...\n");
            }
        }
   return 1;
}
 
string to_gems()
{ return "һЩ�챦ʯ��è��ʯ����䡢ɺ��֮��ģ������ۻ����ҡ�\n"; }
 
string to_china()
{ return "��Щ�������ǹ�Ҥ��Ʒ��ɫ������Ͷ�������֮ѡ��\n"; }
 
string to_plates()
{ return "�������������������ʿս�ס�ŵ�ٴ�½����ʿװ����Ĭ��˹�˵�ս�ۡ�\n"
         "ǰ������Ⱦ��������Ѫ�Ŀ��ס���Щ���Բ�ͬʱ�յĿ���ֻ��һ����ͬ��\n"
         "��ɫ���Ǿ��Ƕ�������(polish)��һ����Ⱦ�����������Ľ���ɫ��\n"; }
 
string to_mirror()
{
  if (this_player()->query_temp("mirror_ok"))
   {return "���澵����ҫ��һ������Ĺ�â���������������ȥ��(touch)����\n";
   ent=2;}
  else{
   return "���澵���ƺ����ⷿ��������۵�������ˡ������⾵�ӻ�ȱ��һ�ǡ�\n";
      }
}
 
void reset()
{
  ::reset();
  ent=1;
}
