#include "../story.h"

inherit ROOM;
int have_head=1;
void create()
{
        ::create();
	set_short("���");
	set_long(@LONG
���ǰ�����߹��Ķ�Ѩ���㷢������Ŀ����ǳ�Ǭ�������ů���ˣ��ഫ��
��Ƶ۴�ս��ȣ���ȴ��˸�������˱�����ͷ­�������촦��һ��Ϊ��������һ
���ݱ������������ֽ��γأ��������ˮ�ʺ�ɫ�����Ƕ�˵������ȵ�Ѫ����
���ɵġ��ڽ������һ����Ĺ������Ƶ�������������֣�������������˸���Ĺ
����ĳ�ֽ��䣬�����������;�����¼�ֻ��������Ĺ���Է�������
LONG
	);
        set( "exit_suppress", ({
          "su"}) );
	set("exits", ([
          "southup" : SAREA"spell3",
               "su" : SAREA"spell3"
        ]) );
	reset();
}
void init()
{
   add_action("do_auction","auction");
   add_action("do_search","search");
}
int do_search(string arg)
{
   object head; 
   if ( !have_head ) return 0;
   have_head=0;
   write("�������ң������Ա߷�Ĺ������һ�ߡ��壡");
   if ( ( this_player()->query_perm_stat("str") ) < 10 ) {
     write("��ϧ�������������޷�������������\n");
     return 1;
   }
   write("����������������\n");
   head=new(SITEM"head1");
   head->move(this_object());
   call_out("recover",900);
   return 1;
}
void recover()
{
   have_head=1;
}
int do_auction(string arg)
{
   write("\n�����Ȼ��������������޷�רע�����������\n\n");
   return 1;
}
