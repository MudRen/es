#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("��ԭ");
	set_long(@LONG
��������һ���տ��Ĳ�ԭ�������ϱ��ǲ�ԭ�����죬�����Ǵ���Ⱥ���ڲ�ԭ��
������ЩСС�İ�������������ɫ���ʡ�������һ�ţ�����������Ũ������ζ����
��֮�⣬һȺҰ�����������յش����ڻ��Լ䣬���ز������ۡ������������߳�
���˸߼�ͷ����ֲ����治ʱ����Ұ�޵Ľ���������������е�ë���Ȼ������
�����룬��û��ǲ�Ҫ���Ǳ���ȥ�����ⷢ��Σ�ա�
LONG
	);
	set("light",1);
	set("exits", ([ 
            "east" : SAREA"plain4",
           "south" : SAREA"plain1",
        ]) );
	reset();
}
void init()
{
    add_action("do_search","search");
    add_action("do_down","climb");
}
int do_search(string arg)
{
   write("�㷢���ڱ��ߵ�������һ����Ѩ����������ȥ(climb down)̽��������\n");
   return 1;
}
int do_down(string arg)
{
   if ( !arg || arg!="down" ) return notify_fail("Syntax : <climb down>\n");  
   this_player()->move_player(SAREA"hole1",({
        "%s����������һ��С��Ѩ�\n",
        "%s�������˽�����\n"}),"");
   return 1;                            
}