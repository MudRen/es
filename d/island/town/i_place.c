#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("���������¹�");
     set_long(@C_LONG
����������˵�פ����´����ڴ�����´�����ҪĿ����Ϊ��������
����������ϵ��Э�����⿪�����������ķ�չ�����ǣ�����Ҫ��Ŀ�Ĳ�
���������������ḻ����Ѷ�����ħ�弰��ʿ�������¶�̬��
C_LONG
             );
     set("light",1);
     set("exits",([
               "north"  : ITOWN"square06"
            ]) );
     set("objects",([
               "lady"  : IMON"lady" ]) );
     reset();
#include <replace_room.h>
 }