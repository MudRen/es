#include "../tsunami.h"

//inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set_short("����");
    set_long(@LONG
��������Ҳ��ң�����ƽʱ��ȡ�����������ٵĵط���ֻ��һ��
�������ǰ���Ըߵ�̨�����룬���Ե�ǽ�Ϲ�������ɽˮ����������ħ��ȫ
���İ�ͼ���᷽��ǽ������ƽƽ�����Ĺ�����գ���������ʱ���Ĺ��١���
Ȼէ��֮�²�����׳�ۣ�������ָ��۹�����ͼ�����Ǳ�¶���š�
LONG
             );
    set("exits",([
        "west":CITY"inway3",
        "south":CITY"inhouse3",
        "north":CITY"inhouse1"]) );
    set("light",1);
 /*   create_door("south","north",([
         "keyword":({"oak door","door"}),
         "status":"closed",
         "name":"Oak door",
         "c_name":"��ľ��",
         "c_desc":"һ�Ⱥ��ؽ�ʵ���̹���������ľ��"
         ]) );*/
    reset();
}