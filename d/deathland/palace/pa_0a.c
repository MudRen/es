
#include "../echobomber.h"

inherit ROOM;
void create()
{
	::create();
 set_short("","�����Ӱ����������");
  set_long(@Long
Long
,@CLong
�����Ƕ����Ӱ���������� . һ�������ֵֹĿ�ƿ��\��\������(desk)��, ���⻹
��ʮ�������(closet)�������������.��������������һ��ͼ��ݶ�������һ������
��ס��.
CLong
);

set("c_item_desc",([
    "desk":"����\��\����һ�ѿ�ƿ��.�������Щƿ��Ӧ����ĳЩʵ�������µ�.\n",
    "closet":"������һЩ�ù�������д����.\n",
    "book":"������д����\n"
    ]) );
    
set("exits",([
              "north":Deathland"/palace/pa_05",
             ]));
#include <../replace_room.h>
}
