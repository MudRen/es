#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("�ݵ�");
	set_long( 
@LONG_DESCRIPTION
����û�����Ե�·�����ߣ���վ��һ��Ƭ�ݵ��м䣬�ݵسʻ���ɫ��ÿ���з紵
�������еĲݾ��������ҡҷ����ͬ����һ�㣬��ϸ�۲�����ƺ��м���С�ض�����
����������֮��Ķ�������ｨ�����ǵķ��ӣ�����Σ�յĵط���������ণ���΢
�е�紵�ݶ�������ʹ�˾��ĵ�����
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "southwest" : ONEW"wild7",
     "southeast" : ONEW"wild11", ]) );
set( "objects", ([
     "worm":OMONSTER"worm",
     ]) );
set_outside("eastland");
reset();
#include <replace_room.h>
}
