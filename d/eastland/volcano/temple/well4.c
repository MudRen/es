#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "����" );
	set_long(
@LONG
����������ھ��ľ��ס�ǰ��һƬ������������һ��������������Ǵ����ﴫ����
���Һ�������������������ӡ�
LONG
	);
	set( "exits", ([
             "south" : OTEMP"well3",
	     "north" : OTEMP"palace1",
	]) );
        reset();
}
