#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "west9", "��·" );
	set_long(@C_LONG
������������һ������ʯ���̳ɵĴ�·��,��·���굽�����ƺ����Ǿ�ͷ����
·���ܴ�,Լ������һƥ����ʻ�Ŀ�ȡ���·�Գ���һЩ���ι�״��ֲ�� ,������
��������಻֪����С��,С���������е㵭������ζ, ��ζ��˵������ʹ������
����������������, ��ʱ�㷳�վ�ʧ,վ���������������ɾ���������һ��Ƭ����
��,���ϱߵ������ٹ�ȥ��һЩ������Сɽ����Ķ�����һ��С����( house )��
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                        "north":DBEGGAR"west7.c"	              
	]) );
        set("c_item_desc",([
               "house":"һ����שͷ���ķ���,�ƺ����Խ�ȥ���� ( enter ) ��\n"
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
        this_player()->move_player(DBEGGAR"vice_master_room",({
              "%s������һ��ש���ķ��ӡ�\n",
              "%s���������˽���.\n"}),"");
        return 1;
     }
     else {
        write("�����������?\n");
        return 1;
     }
}      