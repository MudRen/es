#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("ӳ����㳡");
     set_long(@C_LONG
�������ӳ�����������Ĺ㳡����������һƬƬ�Ĵ�ʯ�壬��������
����ֲ���ã��շ���Ҷ�������������������������������ɡ��ڹ㳡��
�м䣬������һ����ɫ�������Ľ����û�������Զ�������ĺ�ƽ��
���á���������������ȴ���˽�ȥ�ιۣ����ᣬ��һ������ڵ�Ŷ��
C_LONG
             );
     set_outside("island");
     set("light",1);
     set("exits",([
                 "east" : ITOWN"museum",
                 "west" : ITOWN"town04",
               "south"  : ITOWN"square04",
               "north"  : ITOWN"square02"
            ]) );
     set("objects",([
                "vendor":IMON"vendor"
                     ]));
     reset();
 }