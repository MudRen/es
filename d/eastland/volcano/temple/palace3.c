#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
        object ob;

	::create();
	set_short("�������" );
	set_long(
@LONG
���Ǿ������Ĵ������微���е��׽���һ�����˱����Ź�ˮ�弰��»��ϲ��
������ͼ��Χ�ƣ����\�����������̼��ߣ�ʮ�����������������ƿ������ܼⶥ��
������ۼ����̻Ի͡���ǰ��������Բ���ϵ���������ɵĽ�������̬������ƽ���ڱ�
���������Ǿ�����������վ�������һ�����Ӣ��ͦ�Σ�Ŀ�⾼������������������
�ʹ�����������ĵط���������СС�ľ����ƺ������۵��²����ࡣ���߿�ͨ������
���޹������߿�ͨ���������޹���
LONG
	);
	set( "exits", ([
             "south" : OTEMP"palace2",
             "west" : OTEMP"palace4",
	     "east" : OTEMP"palace5",
	]) );
        set("objects", ([
            "lift_guard":OMONSTER"left_guard",
            "right_guard":OMONSTER"right_guard"
            ]) );
        set("light",1);
        reset();
}
