#include "../island.h"

inherit ROOM;

void create()
{
     object knight;
     ::create();
     
     set_short("ʷ��������");
     set_long(@C_LONG
������Ǻ�ƽ�����õĶ�¥������������ٳɺ�ƽ�ߡ�ʥ��ʿ���Ľ�
������ר����ά������İ�ȫ��������ֻ������������һ��ׯ�����µ�
���գ�����˴�����ñ�����������飬��Ȼ����ܻ�ܿ�ͻ��⵽��Ӧ
Ŷ��
C_LONG
             );
     set("light",1);
     set("exits",([
                 "down" : ITOWN"museum"
            ]) );
     set("objects",([
           "monk": IMON"e-shi",
           "trashcan" : "/obj/trashcan"
          ]) );
     set("no_embattle",1);
     set("no_demand",1);
     knight=new(IMON"holy_knight");
     knight->move(this_object());     
     reset();
 }

int clean_up() { return 0; } 