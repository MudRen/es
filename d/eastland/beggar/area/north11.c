#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "north11", "��·" );
	set_long(@C_LONG
������������һ������ʯ���̳ɵĴ�·��,��·���굽�����ƺ��ѵ���ͷ����
·���ܴ�,Լ������һƥ����ʻ�Ŀ�ȡ���·�Գ���һЩ���ι�״��ֲ�� ,������
��������಻֪����С��,С���������е㵭������ζ, ��ζ��˵������ʹ������
����������������, ��ʱ�㷳�վ�ʧ,վ���������������ɾ�����������һ��Ƭ��
��,��������һ����ɫ�Ľ����� ( building ) ԭ���ǡ����Ʒ���������
C_LONG
	);
        set_outside("noden");
        set( "exit_suppress", ({
                        "west" }) );
	set( "exits", ([
               "north":DBEGGAR"north10.c",
	        "west":DBEGGAR"forest1.c"
	]) );
        set("c_item_desc",([
               "building":"һ����ɫ�Ľ�����,�������ǰ������ֻʯʨ�ӡ�\n"
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
    if (str=="building") {
        this_player()->move_player(DBEGGAR"master_room",({
            "%s������һ�䰫���ķ��ӡ�\n",
            "%s���������˽���.\n"}),"");
        return 1;
    }
    else {
        write("�������������?\n");
        return 1;
    }
}    