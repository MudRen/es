#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "north3", "��·" );
	set_long(@C_LONG
������������һ����Ϊ���Ĵ�·��,Լ��������ƥ���С���·���ϡ�����
�����졣������·�������Ǭ����,·�Ե�ֲ���޼��ĺ�����,������������,����
�㳡��Ƭ��ͺͺ�ľ������ǲ��ɶ���Ͼ����������Ӽ����ϴ�����,��˵�Ǵ���
����ĵ�·���������, ȴ�������κ��˹������������ĺۼ�,��һ���ǳ����
ĳλ����֮�֡�������һ��������,ԭ���ǡ�н������ջ ( wine shop )��
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
             "south":DBEGGAR"north2.c",
             "north":DBEGGAR"north5.c"
	]) );
        set("c_item_desc",([
             "wine shop":"һ������ߵķ���,�ƺ����Խ�ȥ���� ( enter ) ��\n"
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
    if (str=="wine shop") {
       this_player()->move_player(DBEGGAR"wine_shop",({
           "%s�����˿�ջ�\n",
           "%s���������˽���.\n"}),"");
       return 1;
    }
    else {
       write("�����������?\n");
       return 1;
    }
}