#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("�ʹ����");
	set_long( @LONG
ӡ�����������һ������ӵ�����������������ɫ���Σ�ԭ�����������µ�
����ǽ�ڶ����ûƽ��̳ɣ��ԵĹ���ʮ�㣡���Ի����ĸ������ɵľ޴����ӣ���
Ȼÿһ���̻��Ķ���������̬����ֻֻ���ζ��أ����鲻һ����Ǳ��أ���������
���𣬽���������צ����������̾Ϊ��ֹĿ��Ͼ�ѣ��ɶ��칤��Ϊ����Ī��֮�죡
�������Ը�վ���Ĺ��佫�����������ꡣ
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "north" : SCITY"palace4",
           "south" : SCITY"palace2"
        ]) );
        set( "objects", ([
           "scholar" : SWMOB"wiz_scholar1",
           "general" : SWMOB"wiz_general1"
        ]) );
	reset();
}
