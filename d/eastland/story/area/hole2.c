#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��Ѩ");
	set_long(@LONG
��������һ���ڰ��Ķ�Ѩ������ն������ƺ�û���κζ���������֮�⣬���
������ǳ������������л���Щ��ù��ζ�����������е���������������ʱ
����Щ�����˻�����������ɲ��Ѽ��������ڵ��Ͽ���һ�Ѻ��ǣ�˵������ʵ�ڲ�
�Ǹ���ȫ�ĵط��������ǽ��� (forbidden_ground) ����˵����Ҫ�߱���������ף
�������ײ��ܰ�ȫ���ݵ�ͨ����
LONG
	);
        set( "exit_suppress", ({
          "nd","su"}) );
	set("exits", ([
            "southup" : SAREA"hole1",
          "northdown" : SAREA"spell1",
                 "su" : SAREA"hole1",
                 "nd" : SAREA"spell1"
        ]) );
        set("objects", ([
         "lion#1" : SMOB"lion1",
         "lion#2" : SMOB"lion1",
         "lion#3" : SMOB"lion1"
        ]) );          
	set("pre_exit_func",([
	 "northdown" : "do_north",
	        "nd" : "do_north"
	]) );
	reset();
}
int do_north()
{
   if ( present("white lion",this_object()) ) {
      write("\n������ʨ��ס�����ȥ·��\n\n");
      return 1;
   }
   if ( this_player()->query_temp("mounting") ) {
      write("\n�����������ⷢ��Σ�ա�\n\n");
      return 1;
   }   
   return 0;
}