#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "s2w1", "��н���塻�㳡" );
	set_long(@C_LONG
����һ��Ƭ��ɰ�㳡,�Ա���һ�Ŵ�����������Ϊ��ؤ����ӳ��ڴ˴�����
��,���Ե����Եù�ͺͺ��һ���Ӳ�Ҳû�С���ʱ���εĺܴ�Ю��������Ļҳ�
,������ÿ���ϱߵĸ�ɽ��������ɽ�硻, ������۾�����������ǡ�ؤ��ⶨ
��һЩˮ�����ֵĹ���, ���Ǵ���ȱ����һ��Ƭ�յؿ��Թ���������ϰ,����ÿ��
�����ֵ��Ƥ�Ĺ����ͻ����˷���,��Ǻ����ǻ��ǵü���������ȥ���������ͱ�
���ǹ㳡�ļ�������, �ϱ�����ɽ�¡�
C_LONG
	);
	set_outside( "noden" );
	set( "exits", ([
                      "east":DBEGGAR"south4.c",
                      "west":DBEGGAR"s4w2.c",
	              "north":DBEGGAR"s1w1.c"
	]) );
        set("c_item_desc",([
                 "tree":"һ�Ŵ�����\n"
        ]) );
     reset();
}
void init()
{
   add_action("to_climb","climb");
}
int to_climb(string str)
{
   if (!str) return 0;
   if (str=="tree") {
       this_player()->move_player(DBEGGAR"tree1",({
            "",
            "%s���������˽�����\n"}),"");
       return 1;
   }
   else {
   write("��������������?\n");
   return 1;
   }
}
