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
                 "east" : ITOWN"square06",
                 "west" : ITOWN"square04",
               "south"  : ITOWN"town06",
               "north"  : ITOWN"museum"
            ]) );
     reset();
#include <replace_room.h>
 }