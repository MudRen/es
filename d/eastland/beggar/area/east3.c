#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "east3", "��·" );
	set_long(@C_LONG
������������һ������ʯ���̳ɵĴ� ·�ϡ���·�򶫡����������졣��·��
�ܴ�,Լ������һƥ����ʻ�Ŀ�ȡ���·�Գ���һЩ���ι�״��ֲ�� ,���������
����಻֪����С��,С���������е㵭������ζ, ��ζ��˵������ʹ�����Ŀ���
������������,��ʱ�㷳�վ�ʧ,վ���������������ɾ����ϱ���һ���̵�,������
���Խ�ȥ�����Ƿ���ʲ����Ҫ�ġ�
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "east":DBEGGAR"east4.c",
                      "west":DBEGGAR"east2.c"
	]) );
        set("c_item_desc",([
                  "store":"һ�䲻�ܴ�ķ���,�ƺ����Խ�ȥ���� ( enter ) ��\n"
        ]) );
     reset();
}
void init()
{
   add_action("to_enter","enter");
}
int to_enter(string str)
{
   if (!str) return 0;
   if (str=="store") {
      this_player()->move_player(DBEGGAR"store",({
           "%s������һ�䲻�ܴ�ķ��ӡ�\n",
           "%s���������˽���.\n"}),"");
      return 1;
   }
   else {
      write("�����������?\n");
      return 1;
   }
}   