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
ȫ�ĵط����ϱ��ǽ��أ���˵����Ҫ�߱���������ף�������ײ��ܰ�ȫ���ݵ�ͨ��
��
LONG
	);
        set( "exit_suppress", ({
            "nd","su"}) );
	set("exits", ([
            "southup" : SAREA"spell1",
          "northdown" : SAREA"spell3",
                 "su" : SAREA"spell1",
                 "nd" : SAREA"spell3",
        ]) );
        set("objects", ([
         "dog#1" : SMOB"dog1",
         "dog#2" : SMOB"dog1",
         "dog#3" : SMOB"dog1",
        ]) );
	reset();
}
void init()
{
   add_action("do_auction","auction");
}
int do_auction(string arg)
{
   write("\n�����Ȼ��������������޷�רע�����������\n\n");
   return 1;
}