#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��ԭ");
	set_long( @LONG
��ĿԶ����Ƭ�������ģ�����������ͨ�徧Ө�������κγ�ɳ�ı�ԭ������Ƭ
�Ử����ĵ����ϣ�����������಻֪����������ÿ���ߡ��˱�����߶��һ��
�������ϣ�ȫ������һƬ���£�����ȴ����֦��Ҷ��������Ρ������ڱ��߻���
һ��¡������Լ���߸ߵ�С����
LONG
	);
	set( "exits", ([ 
           "north" : SCITY"ice2",
           "south" : SCITY"ice1",
            "east" : SCITY"ice2",
            "west" : SCITY"ice2",
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
   add_action("do_enter","enter");
}
int do_search(string arg)
{
   if (arg!="cave") {
      write("�������ң����ֱ��ߵı���Ȼ��һ��С��Ѩ(cave)��\n");
      return 1;
   }
   write("����һ���߿��Բ����������е������Խ�ȥ(enter cave)������\n");
   return 1;
}
int do_enter(string arg)
{
   if (!arg||arg!="cave")
     return notify_fail("����Ҫ��ȥ���\n");
   write("����뱱�߱����һ��С��Ѩ�\n");
   this_player()->move_player(SCITY"ihole1",({
       "%s�����˱����һ��С��Ѩ��\n",
       "%s���������˽���.\n"}),"");
   return 1;
}