#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("ħ��ͨ������");
     set_long(@C_LONG
������������ҵ�פ����´����ڴ������Ų�������Ϊ�������ð�ͨ
����������Ӧ��ħ��Ŀǰ�Ľ���ʱ�ڣ����ɾͽ��������������¹ݼ���ʿ
У����һ��һ����
C_LONG
             );
     set("objects",([
             "elder" : IMON"elder"
                   ]));         
     set("light",1);
     set("exits",([
               "west"  : ITOWN"square08"
            ]) );
     reset();
#include <replace_room.h>
 }