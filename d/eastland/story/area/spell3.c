#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��Ѩ");
	set_long(@LONG
�����ǽ�������Ķ�Ѩ���ն������ƺ�û���κζ���������֮�⣬��е�����
�ǳ������������л���Щ��ù��ζ�����������е���������������ʱ����Щ
�����˻�����������ɲ��Ѽ��������ڵ��Ͽ���һ�Ѻ��ǣ�˵������ʵ�ڲ��Ǹ���
ȫ�ĵط���
LONG
	);
        set( "exit_suppress", ({
            "nd","su"}) );
        set("pre_exit_func",([
          "northdown" : "do_northdown",
                 "nd" : "do_northdown"
        ]) );
	set("exits", ([
            "southup" : SAREA"spell2",
          "northdown" : SAREA"spell4",
                 "su" : SAREA"spell2",
                 "nd" : SAREA"spell4"
        ]) );
        set("objects", ([
         "dragon" : SMOB"dragon1"
        ]) ); 
	reset();
}
void init()
{
   add_action("do_auction","auction");
}
int do_northdown()
{
   if ( present("thunder dragon",this_object()) ) {
      write("\nӦ����ֹ���򱱶��У�\n\n");
      return 1;
   }      
   return 0;
}
int do_auction(string arg)
{
   write("\n�����Ȼ��������������޷�רע�����������\n\n");
   return 1;
}