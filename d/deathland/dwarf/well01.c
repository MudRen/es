
#include "../echobomber.h"

inherit ROOM;

int squ;
void create()
{
	::create();
set_short("well","����");
  set_long(@Long
Long
,@CLong
һ������ľ�,�������ˮ�Ѿ�Ǭ��\��\.\�������ܳ�������̦,�ƺ�����ȥ����
��һ�����׵���.�ھ�����һ���Ѻ�(crack),�ƺ�ˮ���Ǵ���������ȥ��.
CLong
);

set("c_item_desc",([
    "crack":"@@to_crack",
     ]) );

set("search_desc",([
    "crack":"@@to_search_crack"
     ]) );   

  reset();

}

void init()
{
    add_action("to_climb","climb");
    add_action("to_squeeze","squeeze");
}

int to_squeeze()
{
   if (squ==1) {
     write("���޷�������С���ѷ�\n");
     }
   else
     {
     write("����ǿ�����ȥ���ѷ�\n");
     write("���������������ȥ.\n.\n.\n.\n.\n");
     this_player()->set_explore("deathland#5");
     this_player()->move_player(Deathland"/dwarf/well02",({
      this_player()->query("short")+"���ѷ������ȥ\n",
      this_player()->query("short")+"�����������\n",
      }),"");
     }
   return 1;     
} 

int to_climb()
{
    if ( (int)(this_player()->query_skill("climbing")) >= 60 ) 
      {
       say(this_player()->query("c_name")+"�Ӿ���������������ȥ\n");
       write("����˺ܴ����������������\n");
       this_player()->move_player(Deathland"/dwarf/village_09","SNEAK","");
      } 
    else
      { 
       say(this_player()->query("c_name")+"��ѽ�������Ǻ�����ͬһ���ط�\n");
       write("����˺ܴ����������������������\n");
      }
    return 1;
}

string to_search_crack()
{
    if (squ==1) {
      squ=2;
      return "������ϸ�Ѳ����ѷ�ʱ,�����Աߵ�ʯͷ�е��ɶ�.���ʯͷ����\n"
             "�����ѷ�����\��\��\.\n";
      }
    else
      {
      return "һ����Χʯͷ�����ƶ������ѷ�.\n" ;
      }   
}

string to_crack()
{
  if (squ==1)
    return "һ��СС���ѷ�.\n";
  else 
    return  "һ������Ѻ�,\��\��\�����������(squeeze)��ȥ\n";
}

void reset()
{
  ::reset();
  squ=1;
}
