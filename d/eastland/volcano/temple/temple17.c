#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("������");
	set_long(
@LONG_DESCRIPTION
һ���������������յİ�������������Ķ��˵��л������ͼ����
���﹩����ǻ����룬�ڰ�����Ĵ�˵�л������ǻ��������֮һ��ǽ������
��һ���ڻ�����д�������л��ֵľ���������ϯ�ϵĹ�����Ҳ�����Ůū��
�����ġ����ǳ��������������ź�����Ůūͷ�ϴ���������״���������
Ϊ���˵��ơ�
LONG_DESCRIPTION
	);
set( "exits", ([
     "east": OTEMP"temple9",
     ]) );
set ( "objects", ([
      "l_enforcer":OMONSTER"l_enforcer",
      "wprayer":OMONSTER"wprayer"
      ]) );
set("light",1);
reset();
#include <../replace_room.h>
}
