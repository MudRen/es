
#include "iigima.h"

inherit "/d/noden/drow/in_water";
void create()
{
        ::create();
           set_short("����ˮ��");
        set_long(
@LONG
����Ұ���ʪ����ˮԼ�빫������ŵ�һ�����˵�ùζ����
ˮ��Ϥ涵��������㿴��ʯǽ�����������µ�Ƥ�����Ƕ����ɼ���
���ﻹ��������ġ���������һ��������һ��������ˮ����������
���Ա߻�����С͵��õ�����С��һ�ѣ��������ĸ���鹵�С͵��
ǰ��������ɣ��Ĵ����ң�˵���������ҵ����������ı���ࡡ�
LONG
        );
        set( "exits", ([
           "up":DROW"r29",
        ]) );
        set("objects", ([
             "mad snake": DRO"s7",
        ]) );
        set("pre_exit_func",(["west":"check_snake"]));
        reset();
}
int check_snake()
{
     if(present("mad snake",this_object())){
       write("�ͱ�����Ѹ�ٴܶ������������ж���\n");
       return 1;}
       return 0;
}
