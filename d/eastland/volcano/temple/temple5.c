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
     "northwest": OTEMP"temple9",
     "east": OTEMP"temple4",
     "south": OTEMP"temple2",
     ]) );
set("item_desc",([
    "post" : @POST
һ�����Ƽ����������ȫ���ǰ���ɫ�ģ�һ������ɫ��Ƭ�������������۾�
������Ŀ����㡣
POST
       ]));
set("light",1);
reset();
#include <../replace_room.h>
}
