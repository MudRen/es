#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "����" );
	set_long(
@LONG
����������ھ��ľ�ˮ�С�����ˮ���ϴ���΢���Ĺ������⣬�������ȫ��
���ڰ��ͼž����֣������¿�ȥ�����Կ�����Լ�������һ����ߴ����ﴫ����
LONG
	);
	set( "exits", ([
             "up":OTEMP"well1",
	     "down" : OTEMP"well3",
	]) );
        set("pre_exit_func",([
            "up":"to_up",
            ]) );
        reset();
}

int to_up()
{
  this_player()->delete_temp("likefish");
  return 0;
}
