#include <mercury.h>

inherit ROOM;

void create()
{
   ::create();
   set_short( "����ˮ��" );
   set_long(@ANGEL
������һ������ˮ������Ȼ���ڵ��£�������ȴ�Ǻ����£����㲻��
�����Ƶĸо��������㷢�����������Ǭ���ģ��ƺ����˾�ס�����棬��
ͻȻ��һ����ֵĸо�����������ǽ��(wall)�������ط���һ����    
ANGEL
   
         );
	set( "light",0);
	set("item_desc",([
	"wall":"һ����ɫ�ܻҰ���ǽ�ڣ������м����κ�\n"
	]));
	set("search_desc",([
	"wall":"@@to_search_wall"
	]));
        set( "exits", ([
                "east" :MR"tube02"
                ]) );
         reset();                     
}
void init()
{
   add_action("do_enter","enter");
}
int do_enter(string arg)
{
   if(!arg || arg!="gate")
       return notify_fail("��Ҫ��ȥ����?\n");
   write("��С��������������ͨ�������������Ȼ�и�����\n");
   this_player()->move_player(MR"tube04","SNEAK");
   return 1;
}       

string to_search_wall()
{
         this_player()->set_explore("island#12");
  return "������ϸ����ǽ��ʱ����������������һ��ͨ��(gate)\n"
         "�������������(enter)\n";
}            
