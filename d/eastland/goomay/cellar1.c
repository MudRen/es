
#include <goomay.h>

inherit DOORS;
inherit ROOM;

void create()
{
	::create();
	set_short("�ض�");
	set_long( @LONG_DESCRIPTION
����������һ�������ĵض��������ƺ�һ��Ҳ����ʪ��������һ˿˿������
һ��Ҳ����һ��ĵض�����ڵĶ��ں����Ǳ��������ƹ������ĵط��������
��ѵ�΢�⡣
LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"south" : Goomay"cellar2", 
		"up"    : Goomay"blacksmith" ]) );
        set( "objects", ([
                "rat1" : "/d/noden/farwind/monster/rat",
                "rat2" : "/d/noden/farwind/monster/rat",
        ]) );

	create_door( "south", "north", ([
		"keyword" : ({ "steel door", "door" }),
		"name" : "steel door",
		"c_name" : "����",
		"c_desc" : @C_DESC
����һ���ɾ������ɵ��ţ����ؽ�ʵ��������Ȼ�����˻ҳ���˿��
���ǵ��꾫���Ĵ�����Ȼ��΢���Ļ���¾�ǿ�ط��������ĻԹ⣬�ŵ�
���Ͻ�����һ����ɫ�°���ӡ�ǣ�һ������ļǺţ�ͬʱ��Ҳע�⵽��
ӡ���¿���һ�д��֣�

	��	��	��	��	��	��

C_DESC
,		"status" : "locked",
		"lock" : "FIRE_ELEMENT_KEY"
	]) );
	reset();
}
