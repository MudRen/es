#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short("����" );
	set_long(
@LONG
����������ھ��ľ��ס�ˮ���ϵ��κζ������Ѳ��ö�֪���������ȫ�����ڰ�
�ͼž����֣�����ǰ��ȥ�����Կ�����Լ�������һЩ���ߴ����ﴫ����
LONG
	);
	set( "exits", ([
             "up":OTEMP"well2",
	     "north" : OTEMP"well4",
	]) );
        reset();
}
