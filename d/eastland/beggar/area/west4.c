#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "west4", "��·" );
	set_long(@C_LONG
������������һ������ʯ���̳ɵĴ� ·�ϡ���·�򶫡����������졣��·��
�ܴ�,Լ������һƥ����ʻ�Ŀ�ȡ���·�Գ���һЩ���ι�״��ֲ�� ,���������
����಻֪����С��,С���������е㵭������ζ, ��ζ��˵������ʹ�����Ŀ���
������������, ��ʱ�㷳�վ�ʧ,վ���������������ɾ�����ı�����һ����é��
���İ������� ( house )��
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "east":DBEGGAR"west2.c",
                      "west":DBEGGAR"west5.c",
	]) );
        set("c_item_desc",([
              "house":"һ�䰫���ķ���,�ƺ����Խ�ȥ���� ( enter ) ��\n"
        ]) );        
    ::reset();
}
void init()
{
   add_action("to_enter","enter");
}
int to_enter(string str)
{
     if (!str) return 0;
     if (str=="house") {
         this_player()->move_player(DBEGGAR"keeper_room",({
            "%s������һ�䰫���ķ��ӡ�\n",
            "%s���������˽���.\n"}),"");
         return 1;
     }
     else {
     write("�����������?\n");
          return 1;
     }
}                                                  