#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("���������");
	set_long( 
@LONG_DESCRIPTION
һ���������������յİ���������������Ķ��˵��л����ͼ����һ��
�����Ƶľ޴�����(post)���ڽ��䣬ǽ���ϵ�������\����ֵĻ��ƣ��ذ�����һ
���Ļ�ɽ��ƴ�ɵġ�
LONG_DESCRIPTION
	);
set( "exits", ([
     "west": OTEMP"temple1",
     "north": OTEMP"temple6",
     ]) );
set("item_desc",([
    "post" : @POST
һ��������צ�İ�����ȫ�������ɫ�ģ�һ���İ�ɫ��Ƭ�������������۾�
������Ŀ����㡣
POST
       ]));
set("light",1);
reset();
#include <../replace_room.h>
}
