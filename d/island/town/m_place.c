#include "../island.h"

inherit ROOM;

void create()
{
     ::create();
     set_short("��ʿս��������");
     set_long(@C_LONG
�������ʿ����ս����������������Ϊ��������ʵ���ϣ���ȴ����ʿ
��������ؾ��ӵ�αװ��Ϊ���Ǿͽ����������˼�ħ��Ķ���һ����Щ
��ķ紵�ݶ�������һ�����춯�ص�ɱ¾���¾��޷�������
C_LONG
             );
     set_outside("island");
     set("light",1);
     set("exits",([
               "south"  : ITOWN"square02"
            ]) );
     reset();
#include <replace_room.h>
 }
