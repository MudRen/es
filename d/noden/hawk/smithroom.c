
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("������");
        set_light(1);
        set_long( @LONG_DESCRIPTION
���������֮��Ψһ�������̣����������������߹�����ʮ�����ˣ�Ϊ����
������������ڶ�����ʹ������սʿ�ǵ���һ�δλ��˴��������Ļ���������壬
����������ĵ�λ�൱��ߡ�
    ǽ�Ϲ���һ�ž������׵�ͼƬ�����滭���ǰ�����˹ɽ������(god) �������
�����ֵ����Σ�����Χæ�ҵ�������ȣ��Եúܲ������
LONG_DESCRIPTION
        );

        set( "objects", ([
                "smith" : MOB"smith"
                        ]) );

        set( "exits", ([
                "out" : HAWK"room2-16",
                     ]) );
    reset();
}//end of creat

