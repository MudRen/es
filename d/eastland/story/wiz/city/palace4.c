#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�ʹ����");
	set_long( @LONG
��ǰ˫�������������ϣ��������ử����ͯ�Ӷ�ִ���������������ׯ���
�����ڣ�����һ����˿������������ǰ������׽�ƽʱ��������ڣ���ǰ��ʿ��
���Ĺ��䳼����һ�ԣ������������ӳ��ˮ���춥���˵������ɺ������ɶ����
�㶫�����߸�����ͨ���ڵ
LONG
	);
        set("light",1);
	set("get_bag",({}));
	set( "exits", ([ 
           "south" : SCITY"palace3",
            "west" : SCITY"road1"
        ]) );
        set("objects", ([
                   "king" : SWMOB"wiz_king1",
            "bodyguard#1" : SWMOB"wiz_bodyguard2",
            "bodyguard#2" : SWMOB"wiz_bodyguard2",
            "bodyguard#3" : SWMOB"wiz_bodyguard2",
        ]) );
	reset();
}
int clean_up()
{  return 0; }